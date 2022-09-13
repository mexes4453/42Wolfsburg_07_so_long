/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_a_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:30:36 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/01 13:01:38 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nav_utils.h"

int	ft_nav_get_player_cord(t_app *a)
{
	a->map->chr_srch = 'P';
	if (ft_map_iter(a, ft_map_find_chr) != -1)
	{
		ft_printf("Error\nFailed to find player char\n");
		return (-1);
	}
	a->p.x = a->map->idx_x;
	a->p.y = a->map->idx_y;
	return (0);
}

int	ft_nav_is_chr(t_map *m, int x, int y, char chr)
{
	if (m->gmap[y][x] == chr)
		return (-1);
	return (0);
}

int	ft_nav_check_obst(t_app *a, int x, int y)
{
	if (ft_nav_is_chr(a->map, x, y, CHAR_WALL) < 0)
		return (-1);
	else if (ft_nav_is_chr(a->map, x, y, CHAR_COLLECTIBLE) < 0)
	{
		(a->p.collectible)--;
		a->map->gmap[y][x] = '0';
		if (a->p.collectible == COLLECTIBLE_EMPTY)
		{
			ft_app_create_file_img(a, &(a->img), IMG_EXIT_SIGN);
			ft_app_display_map(a, a->map, "E", &(a->img));
		}
	}
	else if (ft_nav_is_chr(a->map, x, y, CHAR_EXIT) < 0)
	{
		if (a->p.collectible != COLLECTIBLE_EMPTY)
			return (-1);
		else
			ft_app_on_player_exit(a);
	}
	return (0);
}
