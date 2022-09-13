/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 09:15:37 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/03 03:24:55 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_app	app;

	if (ft_map_check_input(argc, argv, &app) < 0)
		return (-1);
	ft_app_var_init(&app, app.map);
	ft_app_create_map(argv[1], app.map);
	if (ft_app_is_playable(&app) < 0)
	{
		ft_app_free_gmap(app.map);
		return (-1);
	}
	app.com = mlx_init();
	app.win = mlx_new_window(app.com, app.win_sz_x, app.win_sz_y, PROJ_TITLE);
	ft_app_player_init(&app);
	ft_app_render_imgs(&app);
	mlx_hook(app.win, ON_KEYDOWN, 1L, ft_app_key_handler, &app);
	mlx_hook(app.win, ON_DESTROY, 1L, ft_app_close, &app);
	mlx_loop_hook(app.com, ft_app_runtime, (void *)(&app));
	mlx_loop(app.com);
	return (0);
}
