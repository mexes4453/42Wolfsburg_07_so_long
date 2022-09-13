/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_f_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:04:21 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/01 15:52:57 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_utils.h"

void	ft_app_display_move_cnt(t_app *a)
{
	t_img	img;
	char	*str;

	str = ft_itoa(a->p.cnt_move);
	img.sz_x = IMG_SZ_X * 2;
	img.sz_y = IMG_SZ_Y / 2;
	img.img = mlx_new_image(a->com, img.sz_x, img.sz_y);
	img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), \
											&(img.line_length), \
											&(img.endian));
	ft_app_color_fill_img(&img, 0x00000000);
	mlx_put_image_to_window(a->com, a->win, img.img, 0, 0);
	mlx_destroy_image(a->com, img.img);
	mlx_string_put(a->com, a->win, img.sz_x / 2, img.sz_y / 2, \
													0xFFFFFFFF, str);
	free(str);
}
