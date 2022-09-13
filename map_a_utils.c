/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_a_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:24:41 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/01 13:01:08 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

int	ft_map_is_format_valid(char *fp_map)
{
	char	*str_format;
	size_t	start;
	size_t	len;

	len = ft_strlen(FILE_FORMAT_MAP);
	start = ft_strlen(fp_map) - len;
	str_format = ft_substr(fp_map, start, len);
	if (ft_strncmp(str_format, FILE_FORMAT_MAP, len) != 0)
	{
		ft_printf("Error\nFile format unknown\n");
		free(str_format);
		return (-1);
	}
	free(str_format);
	return (0);
}

/**
 * @brief 	This function reads the map filepath and check that it is valid.
 * 			on error (file does not exist) return -1;
 * 			on success return the file descriptor of the map file (fd).
 * 
 * @param fp_map 
 * @return int 
 */
int	ft_map_open(char *fp_map)
{
	int	fd;

	fd = 0;
	if (ft_map_is_format_valid(fp_map) < 0)
		return (-1);
	fd = open(fp_map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nft_map_open: File does not exist\n");
		return (-1);
	}
	return (fd);
}

size_t	ft_map_get_line_len(char *line)
{
	size_t	line_width;

	line_width = 0;
	if (line == NULL)
		return (-1);
	line_width = ft_strlen(line);
	if (line[line_width - 1] == '\n')
	{
		return (line_width - 1);
	}
	else
		return (line_width);
	return (0);
}

/**
 * @brief 	This functions checks that map width are same over the height.
 * 			returns -1 on error;
 * 			returns 0 on success.
 * 
 * @param fd
 * @return int 
 */
int	ft_map_get_size(int fd, t_map *map)
{
	char	*line;
	size_t	line_len;

	line_len = 0;
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_printf("Error\nmap file is empty\n");
		return (-1);
	}
	map->x = ft_map_get_line_len(line);
	while (line != NULL)
	{
		line_len = ft_map_get_line_len(line);
		if ((line_len - map->x) != 0)
		{
			ft_printf("Error\nmap width varies (not rectangular)\n");
			free(line);
			return (-1);
		}
		(map->y)++;
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	ft_map_read(char *fp_map, t_map *map)
{
	int	fd;

	fd = 0;
	map->x = 0;
	map->y = 0;
	if (fp_map == NULL)
		return (-1);
	fd = ft_map_open(fp_map);
	if (fd < 0)
		return (-1);
	if (ft_map_get_size(fd, map) < 0)
	{
		close(fd);
		return (-1);
	}
	return (0);
}
