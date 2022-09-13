/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_a_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:37:43 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/02 20:52:05 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_utils_bonus.h"

int	ft_app_create_map(char *fp_map, t_map *m)
{
	size_t	counter;
	int		fd;

	counter = 0;
	m->gmap = NULL;
	m->gmap = (char **)malloc(sizeof(char *) * (m->y));
	if (m->gmap == NULL)
		return (-1);
	ft_bzero(m->gmap, sizeof(char *) * (m->y));
	fd = ft_map_open(fp_map);
	if (fd < 0)
		return (-1);
	while (counter < m->y)
	{
		m->gmap[counter] = get_next_line(fd);
		counter++;
	}
	return (0);
}

int	ft_app_free_gmap(t_map *m)
{
	size_t	idx;

	idx = 0;
	while (idx < m->y)
	{
		free (m->gmap[idx]);
		idx++;
	}
	free(m->gmap);
	free(m);
	return (0);
}

void	ft_app_var_init(t_app *a, t_map *m)
{
	a->win_sz_x = IMG_SZ_X * m->x;
	a->win_sz_y = IMG_SZ_X * m->y;
	a->img.img = NULL;
	a->px = 0;
	a->py = 0;
	a->p.p_img.img = NULL;
	a->p.p_img.addr = NULL;
	a->rq = NULL;
	a->cq = NULL;
	a->rc = 0;
	a->matrix = NULL;
	a->dir = 'R';
}

void	ft_app_get_img_cord(size_t x, size_t y, t_app *a)
{
	a->px = (x * IMG_SZ_X);
	a->py = (y * IMG_SZ_Y);
}

int	ft_app_display_map(t_app *a, t_map *m, char *S, t_img *i)
{
	m->idx_y = 0;
	while (m->idx_y < m->y)
	{
		m->idx_x = 0;
		while (m->idx_x < m->x)
		{
			ft_app_get_img_cord(m->idx_x, m->idx_y, a);
			m->chr = m->gmap[m->idx_y][m->idx_x];
			if (m->chr == S[0])
				mlx_put_image_to_window(a->com, a->win, i->img, a->px, a->py);
			m->idx_x++;
		}
		m->idx_y++;
	}
	mlx_destroy_image(a->com, a->img.img);
	return (0);
}
