/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_b_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:43:18 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/01 12:27:59 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app_utils.h"

void	ft_app_create_color_img(t_app *a, u_int32_t color)
{
	a->img.img = mlx_new_image(a->com, IMG_SZ_X, IMG_SZ_Y);
	a->img.addr = mlx_get_data_addr(a->img.img, \
									&(a->img.bits_per_pixel), \
									&(a->img.line_length), \
									&(a->img.endian));
	ft_app_color_fill_img(&(a->img), color);
}

void	ft_app_create_file_img(t_app *a, t_img *i, char *fp_img)
{
	i->img = mlx_xpm_file_to_image(a->com, fp_img, &(i->sz_x), &(i->sz_y));
}

/**
 * @brief 		This function displays img on window. Img objects passed in
 * 				are destroyed if flag = TRUE_DESTORY.
 * todo			Ensure that the pixel cordinate is update accordingly before push
 * 
 * @param a 
 * @param i 
 * @param flag 
 */
void	ft_app_display_img(t_app *a, t_img *i, int flag)
{
	mlx_put_image_to_window(a->com, a->win, i->img, a->px, a->py);
	if (flag == TRUE_DESTROY)
		mlx_destroy_image(a->com, i->img);
}

void	ft_app_color_fill_img(t_img *img, u_int32_t color)
{
	int	x;
	int	y;

	y = 0;
	while (y < img->sz_y)
	{
		x = 0;
		while (x < img->sz_x)
		{
			ft_app_pixel_put_on_img(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_app_pixel_put_on_img(t_img *data, int x, int y, uint32_t color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length);
	dst += (x * (data->bits_per_pixel / BIT_SIZE_BYTE));
	*(unsigned int *)dst = color;
}
