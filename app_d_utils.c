/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:24:03 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/01 13:21:16 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_utils.h"

int	ft_app_key_handler(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
	{
		ft_printf("\nExiting application...\n");
		mlx_destroy_image(app->com, (app->p.p_img.img));
		mlx_destroy_window(app->com, app->win);
		ft_app_free_gmap(app->map);
		mlx_destroy_display(app->com);
		free(app->com);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_D)
		ft_nav_move_right(app);
	else if (keycode == KEY_A)
		ft_nav_move_left(app);
	else if (keycode == KEY_W)
		ft_nav_move_up(app);
	else if (keycode == KEY_S)
		ft_nav_move_down(app);
	return (0);
}

char	**ft_app_create_matrix(t_map *m)
{
	size_t	idx;
	char	**matrix;

	idx = 0;
	matrix = NULL;
	matrix = (char **)malloc(sizeof(char *) * m->y);
	if (matrix == NULL)
		return (NULL);
	ft_bzero(matrix, sizeof(char *) * (m->y));
	while (idx < m->y)
	{
		matrix[idx] = (char *)malloc(sizeof(char) * m->x);
		if (matrix[idx] == NULL)
			return (NULL);
		ft_bzero(matrix[idx], sizeof(char) * (m->x));
		idx++;
	}
	return (matrix);
}

int	ft_app_show_matrix(t_map *m, char **matrix)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < m->y)
	{
		x = 0;
		while (x < m->x)
		{
			ft_printf("\nY(%d), X(%d) -> %d", y, x, (int)matrix[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_app_matrix_del(t_map *m, char **matrix)
{
	size_t	idx;

	idx = 0;
	while (idx < m->y)
	{
		free(matrix[idx]);
		idx++;
	}
	free(matrix);
	matrix = NULL;
}

int	ft_app_init_collectible_queue(t_app *a)
{
	a->p.collectible = 0;
	if (ft_map_iter(a, ft_app_cnt_collectibles) < 0)
		return (-1);
	a->rq = ft_queue_create((int)a->p.collectible);
	a->cq = ft_queue_create((int)a->p.collectible);
	if (a->rq == NULL || a->cq == NULL)
		return (-1);
	return (0);
}
