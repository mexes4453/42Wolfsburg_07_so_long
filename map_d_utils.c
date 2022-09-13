/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:23:46 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/01 13:29:49 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

int	ft_map_check_input(int argc, char **argv, t_app *a)
{
	a->map = (t_map *)malloc(sizeof(t_map));
	if (argc != 2)
	{
		ft_printf("Error\nIncomplete arguments\n");
		free(a->map);
		return (-1);
	}
	if (ft_map_read(argv[1], a->map) < 0)
	{
		free(a->map);
		return (-1);
	}
	if (ft_map_validate(argv[1], a->map) < 0)
	{
		free(a->map);
		return (-1);
	}
	return (0);
}

int	ft_map_get_chr_cord(void *param)
{
	t_app	*a;

	a = (t_app *)param;
	if (a->map->chr == a->map->chr_srch)
	{
		ft_queue_enqueue((a->rq), (int)(a->map->idx_y));
		ft_queue_enqueue((a->cq), (int)(a->map->idx_x));
	}
	return (0);
}
