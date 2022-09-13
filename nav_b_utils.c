/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_b_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:27:22 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/01 12:22:41 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nav_utils.h"

int	ft_nav_move(t_app *a, int x, int y)
{
	if (ft_nav_check_obst(a, x, y) < 0)
		return (-1);
	ft_app_get_img_cord(a->p.x, a->p.y, a);
	ft_app_create_color_img(a, 0x00000000);
	ft_app_display_img(a, &(a->img), TRUE_DESTROY);
	(a->p.cnt_move)++;
	ft_printf("\nMoves: %d", a->p.cnt_move);
	ft_app_display_move_cnt(a);
	return (0);
}

int	ft_nav_move_right(t_app *a)
{
	t_player	*obj;

	obj = &(a->p);
	if (ft_nav_move(a, obj->x + 1, obj->y) < 0)
		return (-1);
	(obj->x)++;
	ft_app_get_img_cord(obj->x, obj->y, a);
	ft_app_display_img(a, &(obj->p_img), FALSE_DESTROY);
	return (0);
}

int	ft_nav_move_left(t_app *a)
{
	t_player	*obj;

	obj = &(a->p);
	if (ft_nav_move(a, obj->x - 1, obj->y) < 0)
		return (-1);
	(obj->x)--;
	ft_app_get_img_cord(obj->x, obj->y, a);
	ft_app_display_img(a, &(obj->p_img), FALSE_DESTROY);
	return (0);
}

int	ft_nav_move_up(t_app *a)
{
	t_player	*obj;

	obj = &(a->p);
	if (ft_nav_move(a, obj->x, obj->y - 1) < 0)
		return (-1);
	(obj->y)--;
	ft_app_get_img_cord(obj->x, obj->y, a);
	ft_app_display_img(a, &(obj->p_img), FALSE_DESTROY);
	return (0);
}

int	ft_nav_move_down(t_app *a)
{
	t_player	*obj;

	obj = &(a->p);
	if (ft_nav_move(a, obj->x, obj->y + 1) < 0)
		return (-1);
	(obj->y)++;
	ft_app_get_img_cord(obj->x, obj->y, a);
	ft_app_display_img(a, &(obj->p_img), FALSE_DESTROY);
	return (0);
}
