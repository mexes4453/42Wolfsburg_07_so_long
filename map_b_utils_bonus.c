/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_b_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:24:15 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/03 00:13:52 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils_bonus.h"

int	ft_map_is_size_valid(t_map *map)
{
	if ((map->x < MIN_MAP_WIDTH) || (map->y < MIN_MAP_HEIGHT))
	{
		ft_printf("Error\nmap size is invalid min_x(5), min_y(3)\n");
		return (-1);
	}
	return (0);
}

int	ft_map_invalid(char *CHARS, t_map *m)
{
	if (ft_strchr(CHARS, m->chr) == 0)
	{
		ft_printf("Error\nInvalid char (%c) in map\n", m->chr);
		return (-1);
	}
	return (0);
}

int	ft_map_chk_wall(char *S, t_map *m)
{
	if ((m->idx_y == 0) || (m->idx_y == (m->y - 1)))
	{
		if (m->chr != S[0])
		{
			ft_printf("Error\nInvalid map: missing wall bound chr\n");
			return (-1);
		}
	}
	else
	{
		if (m->idx_x == 0 || m->idx_x == m->x - 1)
		{
			if (m->chr != S[0])
			{
				ft_printf("Error\nInvalid map: missing wall bound chr\n");
				return (-1);
			}
		}
	}
	return (0);
}

int	ft_map_is_chr(char *fp_m, t_map *m, char *S, int (*f)(char *, t_map *))
{
	int	fd;

	m->idx_y = 0;
	m->cnt_char = 0;
	fd = ft_map_open(fp_m);
	while (m->idx_y < m->y)
	{
		m->idx_x = 0;
		m->str_line = get_next_line(fd);
		while (m->idx_x < m->x)
		{
			m->chr = m->str_line[m->idx_x];
			if (f(S, m) < 0)
			{
				free(m->str_line);
				return (-1);
			}
			m->idx_x++;
		}
		free(m->str_line);
		m->idx_y++;
	}
	return (0);
}

int	ft_map_dup(char *S, t_map *m)
{
	if (m->chr == S[0])
		(m->cnt_char)++;
	if (m->cnt_char > 1)
	{
		ft_printf("Error\nchar duplicated (%c)\n", m->chr);
		return (-1);
	}
	return (0);
}
