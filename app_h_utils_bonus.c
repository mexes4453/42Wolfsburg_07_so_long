/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_h_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:04:21 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/03 00:13:27 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_utils_bonus.h"

int	ft_app_animate_enemy_on_left_space(t_app *a)
{
	if (a->map->gmap[a->t_r][a->t_c - 1] == '0')
	{
		ft_queue_enqueue(a->rq, a->t_r);
		ft_queue_enqueue(a->cq, a->t_c - 1);
		ft_queue_enqueue(a->dir_enemy, 0);
		a->px = a->t_c * IMG_SZ_X;
		a->py = a->t_r * IMG_SZ_Y;
		ft_app_create_color_img(a, 0x00000000);
		ft_app_display_img(a, &(a->img), TRUE_DESTROY);
		a->map->gmap[a->t_r][a->t_c] = '0';
		a->px = (a->t_c - 1) * IMG_SZ_X;
		a->py = a->t_r * IMG_SZ_Y;
		ft_app_create_file_img(a, &(a->img), IMG_ENEMY_L);
		ft_app_display_img(a, &(a->img), TRUE_DESTROY);
		a->map->gmap[a->t_r][a->t_c - 1] = 'A';
		return (0);
	}
	return (-1);
}

int	ft_app_animate_enemy_on_right_space(t_app *a)
{
	if (a->map->gmap[a->t_r][a->t_c + 1] == '0')
	{
		ft_queue_enqueue(a->rq, a->t_r);
		ft_queue_enqueue(a->cq, a->t_c + 1);
		ft_queue_enqueue(a->dir_enemy, 1);
		a->px = a->t_c * IMG_SZ_X;
		a->py = a->t_r * IMG_SZ_Y;
		ft_app_create_color_img(a, 0x00000000);
		ft_app_display_img(a, &(a->img), TRUE_DESTROY);
		a->map->gmap[a->t_r][a->t_c] = '0';
		a->px = (a->t_c + 1) * IMG_SZ_X;
		a->py = a->t_r * IMG_SZ_Y;
		ft_app_create_file_img(a, &(a->img), IMG_ENEMY_R);
		ft_app_display_img(a, &(a->img), TRUE_DESTROY);
		a->map->gmap[a->t_r][a->t_c + 1] = 'A';
		return (0);
	}
	return (-1);
}
