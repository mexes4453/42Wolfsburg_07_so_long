/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_c_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:24:01 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/31 12:22:50 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

int	ft_map_min(char *S, t_map *m)
{
	if (m->chr == S[0])
		(m->cnt_char)++;
	if ((m->idx_y == (m->y - 1)) && ((m->idx_x == (m->x -1))))
	{
		if (m->cnt_char == 0)
		{
			ft_printf("Error\nchar missing (%c)\n", S[0]);
			return (-1);
		}
	}
	return (0);
}

int	ft_map_validate(char *fp_map, t_map *m)
{
	if (ft_map_is_size_valid(m) < 0)
		return (-1);
	if (ft_map_is_chr(fp_map, m, MAP_VALID_CHARS, ft_map_invalid) < 0)
		return (-1);
	if (ft_map_is_chr(fp_map, m, MAP_VALID_CHARS, ft_map_chk_wall) < 0)
		return (-1);
	if (ft_map_is_chr(fp_map, m, "P", ft_map_dup) < 0)
		return (-1);
	if (ft_map_is_chr(fp_map, m, "E", ft_map_dup) < 0)
		return (-1);
	if (ft_map_is_chr(fp_map, m, "P", ft_map_min) < 0)
		return (-1);
	if (ft_map_is_chr(fp_map, m, "E", ft_map_min) < 0)
		return (-1);
	if (ft_map_is_chr(fp_map, m, "C", ft_map_min) < 0)
		return (-1);
	if (ft_map_is_chr(fp_map, m, "0", ft_map_min) < 0)
		return (-1);
	return (0);
}

int	ft_map_iter(t_app *a, int (*f)(void *))
{
	t_map	*m;

	m = a->map;
	m->idx_y = 0;
	while (m->idx_y < m->y)
	{
		m->idx_x = 0;
		while (m->idx_x < m->x)
		{
		m->chr = m->gmap[m->idx_y][m->idx_x];
			if (f((void *)a) < 0)
				return (-1);
			m->idx_x++;
		}
		m->idx_y++;
	}
	return (0);
}

int	ft_map_find_chr(void *param)
{
	t_app	*a;

	a = (t_app *)param;
	if (a->map->chr == a->map->chr_srch)
		return (-1);
	return (0);
}
