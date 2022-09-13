/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_g_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:04:21 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/03 00:13:19 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_utils_bonus.h"

int	ft_app_enemy_spot(t_app *a)
{
	a->t_c = 0;
	a->t_r = 0;
	a->t_d = 0;
	ft_queue_pop(a->rq, &(a->t_r));
	ft_queue_pop(a->cq, &(a->t_c));
	a->t_c -= 1;
	if (a->map->gmap[a->t_r][a->t_c] == '0')
	{
		a->map->gmap[a->t_r][a->t_c] = 'A';
		ft_queue_enqueue(a->rq, a->t_r);
		ft_queue_enqueue(a->cq, a->t_c);
		ft_queue_enqueue(a->dir_enemy, a->t_d);
		a->px = a->t_c * IMG_SZ_X;
		a->py = a->t_r * IMG_SZ_Y;
		ft_app_create_file_img(a, &(a->img), IMG_ENEMY_L);
		ft_app_display_img(a, &(a->img), TRUE_DESTROY);
	}
	return (0);
}

int	ft_app_render_enemy(t_app *a)
{
	int	idx;

	idx = 0;
	if (ft_app_init_collectible_queue(a) < 0)
	{
		ft_printf("\nError: ft_app_render_enemy");
		return (-1);
	}
	a->map->chr_srch = 'C';
	if (ft_map_iter(a, ft_map_get_chr_cord) < 0)
		return (-1);
	a->dir_enemy = ft_queue_create(a->p.collectible);
	while (idx < a->p.collectible)
	{
		ft_app_enemy_spot(a);
		idx++;
	}
	return (0);
}

int	ft_app_animate_enemy(t_app *a)
{
	ft_queue_pop(a->rq, &(a->t_r));
	ft_queue_pop(a->cq, &(a->t_c));
	ft_queue_pop(a->dir_enemy, &(a->t_d));
	if (a->t_d == 0)
	{
		if (ft_app_animate_enemy_on_left_space(a) != 0)
			ft_app_animate_enemy_on_left_obst(a);
		if (a->map->gmap[a->t_r][a->t_c - 1] == 'P')
			ft_app_close((void *)a);
	}
	else
	{
		if (ft_app_animate_enemy_on_right_space(a) != 0)
			ft_app_animate_enemy_on_right_obst(a);
		if (a->map->gmap[a->t_r][a->t_c + 1] == 'P')
			ft_app_close((void *)a);
	}
	ft_app_delay();
	return (0);
}

int	ft_app_animate_enemy_on_left_obst(t_app *a)
{
	if ((a->map->gmap[a->t_r][a->t_c - 1] == '1') ||
		(a->map->gmap[a->t_r][a->t_c - 1] == 'C') ||
		(a->map->gmap[a->t_r][a->t_c - 1] == 'E') ||
		(a->map->gmap[a->t_r][a->t_c - 1] == 'A'))
	{
		ft_queue_enqueue(a->rq, a->t_r);
		ft_queue_enqueue(a->cq, a->t_c);
		ft_queue_enqueue(a->dir_enemy, 1);
		a->px = a->t_c * IMG_SZ_X;
		a->py = a->t_r * IMG_SZ_Y;
		a->map->gmap[a->t_r][a->t_c] = '0';
		ft_app_create_color_img(a, 0x00000000);
		ft_app_display_img(a, &(a->img), TRUE_DESTROY);
		ft_app_create_file_img(a, &(a->img), IMG_ENEMY_R);
		ft_app_display_img(a, &(a->img), TRUE_DESTROY);
		a->map->gmap[a->t_r][a->t_c] = 'A';
		return (0);
	}
	return (-1);
}

int	ft_app_animate_enemy_on_right_obst(t_app *a)
{
	if ((a->map->gmap[a->t_r][a->t_c + 1] == '1') ||
		(a->map->gmap[a->t_r][a->t_c + 1] == 'C') ||
		(a->map->gmap[a->t_r][a->t_c + 1] == 'E') ||
		(a->map->gmap[a->t_r][a->t_c + 1] == 'A'))
	{
		ft_queue_enqueue(a->rq, a->t_r);
		ft_queue_enqueue(a->cq, a->t_c);
		ft_queue_enqueue(a->dir_enemy, 0);
		a->px = a->t_c * IMG_SZ_X;
		a->py = a->t_r * IMG_SZ_Y;
		ft_app_create_color_img(a, 0x00000000);
		ft_app_display_img(a, &(a->img), TRUE_DESTROY);
		ft_app_create_file_img(a, &(a->img), IMG_ENEMY_L);
		ft_app_display_img(a, &(a->img), TRUE_DESTROY);
		return (0);
	}
	return (-1);
}
