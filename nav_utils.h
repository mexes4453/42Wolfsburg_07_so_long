/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nav_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 21:27:27 by cudoh             #+#    #+#             */
/*   Updated: 2022/08/31 12:10:06 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NAV_UTILS_H
# define NAV_UTILS_H
# include "so_long.h"

//--- NAV_A_UTILS
int		ft_nav_get_player_cord(t_app *a);
int		ft_nav_is_chr(t_map *m, int x, int y, char chr);
int		ft_nav_check_obst(t_app *a, int x, int y);
//--- NAV_B_UTILS
int		ft_nav_move(t_app *a, int x, int y);
int		ft_nav_move_right(t_app *a);
int		ft_nav_move_left(t_app *a);
int		ft_nav_move_up(t_app *a);
int		ft_nav_move_down(t_app *a);
#endif
