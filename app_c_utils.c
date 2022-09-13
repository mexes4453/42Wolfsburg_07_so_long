/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_c_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:49:47 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/01 12:47:55 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_utils.h"

int	ft_app_cnt_collectibles(void *ptr)
{
	t_app	*a;

	a = (t_app *)ptr;
	if (a->map->chr == 'C')
		(a->p.collectible)++;
	return (0);
}

int	ft_app_close(void *params)
{
	t_app	*a;

	a = (t_app *)params;
	ft_printf("\nExiting application...\n");
	mlx_destroy_image(a->com, (a->p.p_img.img));
	mlx_destroy_window(a->com, a->win);
	ft_app_free_gmap(a->map);
	mlx_destroy_display(a->com);
	free(a->com);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_app_on_player_exit(t_app *a)
{
	if (a->p.collectible == COLLECTIBLE_EMPTY)
		ft_app_close((void *)a);
	return (0);
}

void	ft_app_render_imgs(t_app *a)
{
	ft_app_create_file_img(a, &(a->img), IMG_WALL);
	ft_app_display_map(a, a->map, "1", &(a->img));
	ft_app_create_file_img(a, &(a->img), IMG_COLLECTIBLE);
	ft_app_display_map(a, a->map, "C", &(a->img));
	ft_app_create_file_img(a, &(a->img), IMG_EXIT);
	ft_app_display_map(a, a->map, "E", &(a->img));
	ft_app_create_file_img(a, &(a->img), IMG_PLAYER);
	ft_app_display_map(a, a->map, "P", &(a->img));
	ft_app_display_move_cnt(a);
}

void	ft_app_player_init(t_app *a)
{
	ft_nav_get_player_cord(a);
	ft_app_create_file_img(a, &(a->p.p_img), IMG_PLAYER);
	a->p.cnt_move = 0;
	a->p.collectible = 0;
	ft_map_iter(a, ft_app_cnt_collectibles);
}
