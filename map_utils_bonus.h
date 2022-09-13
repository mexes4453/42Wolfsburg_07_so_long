/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:40:13 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/02 20:49:11 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_BONUS_H
# define MAP_UTILS_BONUS_H
# include "so_long_bonus.h"

//--- MAP_A_UTILS
int		ft_map_is_format_valid(char *fp_map);
int		ft_map_open(char *fp_map);
size_t	ft_map_get_line_len(char *line);
int		ft_map_get_size(int fd, t_map *map);
int		ft_map_read(char *fp_map, t_map *map);
//--- MAP_B_UTILS
int		ft_map_is_size_valid(t_map *map);
int		ft_map_invalid(char *CHARS, t_map *m);
int		ft_map_chk_wall(char *S, t_map *m);
int		ft_map_is_chr(char *fp_m, t_map *m, char *S, int (*f)(char *, t_map *));
int		ft_map_dup(char *S, t_map *m);
//--- MAP_C_UTILS
int		ft_map_min(char *S, t_map *m);
int		ft_map_validate(char *fp_map, t_map *map);
int		ft_map_iter(t_app *a, int (*f)(void *));
int		ft_map_find_chr(void *param);
//--- MAP_D_UTILS
int		ft_map_check_input(int argc, char **argv, t_app *a);
int		ft_map_get_chr_cord(void *param);
#endif
