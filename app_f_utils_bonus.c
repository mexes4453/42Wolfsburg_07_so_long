/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_f_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:04:21 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/03 11:54:21 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_utils_bonus.h"

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

int	ft_app_runtime(void *app)
{
	t_app	*a;

	a = (t_app *)app;
	if (a->dir == 'R')
		ft_app_animate_player_on_right(a);
	else
		ft_app_animate_player_on_left(a);
	ft_app_animate_enemy(a);
	return (0);
}

void	ft_app_delay(void)
{
	long long unsigned int	cnt;
	long long unsigned int	repeat;

	usleep(50000);
	repeat = 999999999999999;
	while (repeat > 0)
	{
		cnt = 9999999900000000;
		while (cnt > 0)
			cnt--;
		repeat--;
	}
}

void	ft_app_animate_player_on_left(t_app *a)
{
	ft_app_get_img_cord(a->p.x, a->p.y, a);
	ft_app_create_file_img(a, &(a->p.p_img), IMG_PLAYER_LU);
	ft_app_display_img(a, &(a->p.p_img), TRUE_DESTROY);
	ft_app_delay();
	ft_app_create_file_img(a, &(a->p.p_img), IMG_PLAYER_L);
	ft_app_display_img(a, &(a->p.p_img), TRUE_DESTROY);
	ft_app_delay();
	ft_app_create_file_img(a, &(a->p.p_img), IMG_PLAYER_LD);
	ft_app_display_img(a, &(a->p.p_img), TRUE_DESTROY);
	ft_app_delay();
}

void	ft_app_animate_player_on_right(t_app *a)
{
	ft_app_get_img_cord(a->p.x, a->p.y, a);
	ft_app_create_file_img(a, &(a->p.p_img), IMG_PLAYER_RU);
	ft_app_display_img(a, &(a->p.p_img), TRUE_DESTROY);
	ft_app_delay();
	ft_app_create_file_img(a, &(a->p.p_img), IMG_PLAYER_R);
	ft_app_display_img(a, &(a->p.p_img), TRUE_DESTROY);
	ft_app_delay();
	ft_app_create_file_img(a, &(a->p.p_img), IMG_PLAYER_RD);
	ft_app_display_img(a, &(a->p.p_img), TRUE_DESTROY);
	ft_app_delay();
}
