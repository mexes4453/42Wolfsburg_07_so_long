/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatype_const_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:39:58 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/02 20:49:37 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATATYPE_CONST_BONUS_H
# define DATATYPE_CONST_BONUS_H
# define IMG_SZ_X (64)
# define IMG_SZ_Y (64)
# define MIN_MAP_HEIGHT (3)
# define MIN_MAP_WIDTH (5)
# define BIT_SIZE_BYTE (8)
# define FLAG_GAME_EXIT (1L)
# define TRUE_DESTROY (1)
# define FALSE_DESTROY (0)
# define PROJ_TITLE ("so_long")
# define FILE_FORMAT_MAP (".ber")
# define MAP_VALID_CHARS ("10ECP")
# define CHAR_WALL ('1')
# define CHAR_COLLECTIBLE ('C')
# define CHAR_PLAYER ('P')
# define CHAR_ENEMY ('A')
# define CHAR_EXIT ('E')
# define COLLECTIBLE_EMPTY (0)
# define IMG_PLAYER_R ("open_r.xpm")
# define IMG_PLAYER_L ("open_l.xpm")
# define IMG_PLAYER_LD ("open_ld.xpm")
# define IMG_PLAYER_LU ("open_lu.xpm")
# define IMG_PLAYER_RD ("open_rd.xpm")
# define IMG_PLAYER_RU ("open_ru.xpm")
# define IMG_ENEMY_R ("enemy_r.xpm")
# define IMG_ENEMY_L ("enemy_l.xpm")
# define IMG_WALL ("wall.xpm")
# define IMG_COLLECTIBLE ("collectible.xpm")
# define IMG_EXIT ("exit.xpm")
# define IMG_EXIT_SIGN ("exit_sign.xpm")
# include <stddef.h>
# include "queue_utils_bonus.h"

enum e_E_APP_EVENT{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_KEYS
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_APP_CLOSE_ICON = -16777904L
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
	int		sz_x;
	int		sz_y;
}			t_img;

typedef struct s_map
{
	size_t	x;
	size_t	y;
	size_t	idx_x;
	size_t	idx_y;
	int		cnt_char;
	char	chr;
	char	chr_srch;
	char	*str_line;
	char	**gmap;
}		t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		collectible;
	size_t	cnt_move;
	t_img	p_img;
}			t_player;

typedef struct s_app
{
	void		*win;
	void		*com;
	int			rc;
	int			win_sz_x;
	int			win_sz_y;
	size_t		px;
	size_t		py;
	t_map		*map;
	t_img		img;
	t_player	p;
	t_queue		*rq;
	t_queue		*cq;
	char		**matrix;
	int			t_r;
	int			t_c;
	int			t_d;
	int			p_r;
	int			p_c;
	char		dir;
	t_queue		*dir_enemy;
}				t_app;
#endif
