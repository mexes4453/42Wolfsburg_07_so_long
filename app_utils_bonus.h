/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_utils_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 17:16:22 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/02 20:49:59 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_UTILS_BONUS_H
# define APP_UTILS_BONUS_H
# include "so_long_bonus.h"

//--- APP_A_UTILS 
int		ft_app_create_map(char *fp_map, t_map *m);
int		ft_app_free_gmap(t_map *m);
void	ft_app_var_init(t_app *a, t_map *m);
void	ft_app_get_img_cord(size_t x, size_t y, t_app *a);
int		ft_app_display_map(t_app *a, t_map *m, char *S, t_img *i);
//--- APP_B_UTILS 
void	ft_app_create_color_img(t_app *a, u_int32_t color);
void	ft_app_create_file_img(t_app *a, t_img *i, char *fp_img);
void	ft_app_display_img(t_app *a, t_img *i, int flag);
void	ft_app_color_fill_img(t_img *img, u_int32_t color);
void	ft_app_pixel_put_on_img(t_img *data, int x, int y, uint32_t color);
//--- APP_C_UTILS 
int		ft_app_cnt_collectibles(void *ptr);
int		ft_app_close(void *params);
int		ft_app_on_player_exit(t_app *a);
void	ft_app_render_imgs(t_app *a);
void	ft_app_player_init(t_app *a);
//--- APP_D_UTILS 
int		ft_app_key_handler(int keycode, t_app *app);
// ---- FUNCTIONS VALIDATE IF GAME IS PLAYABLE
char	**ft_app_create_matrix(t_map *m);
int		ft_app_show_matrix(t_map *m, char **matrix);
void	ft_app_matrix_del(t_map *m, char **matrix);
int		ft_app_init_collectible_queue(t_app *a);
//--- APP_E_UTILS 
int		ft_app_chk_node(t_app *a, t_queue *qp_r, t_queue *qp_c);
int		ft_app_chk_nodes(t_app *a, t_queue *qp_r, t_queue *qp_c);
int		ft_app_srch_paths(t_app *a, t_queue *qp_r, t_queue *qp_c);
void	ft_app_del_queues(t_app *a, t_queue *qp_r, t_queue *qp_c);
int		ft_app_is_playable(t_app *a);
//--- APP_F_UTILS
void	ft_app_display_move_cnt(t_app *a);
//----  FUNCTIONS RENDERS ENEMY
int		ft_app_runtime(void *app);
void	ft_app_delay(void);
void	ft_app_animate_player_on_left(t_app *a);
void	ft_app_animate_player_on_right(t_app *a);
//--- APP_G_UTILS
int		ft_app_enemy_spot(t_app *a);
int		ft_app_render_enemy(t_app *a);
int		ft_app_animate_enemy(t_app *a);
int		ft_app_animate_enemy_on_left_obst(t_app *a);
int		ft_app_animate_enemy_on_right_obst(t_app *a);
//--- APP_H_UTILS
int		ft_app_animate_enemy_on_left_space(t_app *a);
int		ft_app_animate_enemy_on_right_space(t_app *a);
#endif
