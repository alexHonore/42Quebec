/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:21:30 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/08 16:12:07 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

/* linux */
/*
# define ESC 			65307
# define SPACE_KEY 		32
# define A_KEY			97
# define D_KEY			100
# define E_KEY			101
# define M_KEY			109
# define R_KEY				114
# define S_KEY			115
# define W_KEY			119
# define SHIFT_KEY		65505
# define RIGHT_KEY		65363
# define LEFT_KEY		65361
# define DOWN_KEY		65362
# define UP_KEY			65364
*/

/* mac */
# define ESC 53
# define SPACE_KEY 49
# define A_KEY 0
# define D_KEY 2
# define E_KEY 14
# define M_KEY 46
# define R_KEY 15
# define S_KEY 1
# define W_KEY 13
# define SHIFT_KEY 257
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define UP_KEY 126
# define DOWN_KEY 125

/* Colors */
// 0xRRGGBBAA in hex value
typedef enum e_color
{
	TRANSPARENT = 0x00000000,
	TRANSLUCENT = 0x0000007F,
	WHITE = 0xFFFFFFFF,
	BLACK = 0x000000FF,
	RED = 0xFF0000FF,
	GREEN = 0x00FF00FF,
	BLUE = 0x0000FFFF,
	YELLOW = 0xFFFF00FF,
	GRAY = 0x808080FF,
	ORANGE = 0xFFA500FF,
	PURPLE = 0xFF00FFFF,
	CYAN = 0x00FFFFFF,
	PINK = 0xFFC0CBFF,
	BROWN = 0xA52A2AFF,
	SKYBLUE = 0x87CEEBFF,
	LIGHT_GRAY = 0xBBBBBBFF,
	LIGHT_BLUE = 0xADD8E6FF,
	LIGHT_GREEN = 0x90EE90FF,
	LIGHT_YELLOW = 0xFFFFE0FF,
	LIGHT_ORANGE = 0xFFDAB9FF,
	LIGHT_PURPLE = 0xE6E6FAFF,
	LIGHT_SKYBLUE = 0x87CEFAFF,
	DARK_GRAY = 0x404040FF,
	DARK_BLUE = 0x00008BFF,
	DARK_GREEN = 0x006400FF,
	DARK_RED = 0x8B0000FF,
	DARK_ORANGE = 0xFF8C00FF,
	DARK_PURPLE = 0x800080FF,
	DARK_PINK = 0xFF1493FF,
	DARK_YELLOW = 0xBDB76BFF,
	DARK_SKYBLUE = 0x00BFFFFF,
}					t_color;

/* ****** STRUCTS ****** */

typedef enum e_game_status
{
	RUNNING,
	OVER,
}					t_game_status;

typedef struct s_game_info
{
	int				floor_color;
	int				ceiling_color;
	char			*north_texture;
	char			*east_texture;
	char			*south_texture;
	char			*west_texture;
	char			player_direction;
	int				player_x;
	int				player_y;
	int				map_width;
	int				map_height;
	int				**map;
	int				mapstart;
	int				maplen;
	int				bhy_saoul;

}					t_game_info;

typedef struct s_rectangle
{
	int				x;
	int				y;
	int				width;
	int				height;
}					t_rectangle;

typedef struct s_collectible
{
	int				x;
	int				y;
	int				type;
	int				value;
}					t_collectible;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_line_data
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
	int				x;
	int				y;
}					t_line_data;

// pa = player angle
// px = player x position
// py = player y position
// pdx = player x direction
// pdy = player y direction
// cpx = camera plane x
// cpy = camera plane y
// rx = ray x position
// ry = ray y position
// ra = ray angle
// rda = ray delta angle
// rdx = ray direction x
// rdy = ray direction y
// pwd = perp wall distance
// s_dist_x = side distance x
// s_dist_y = side distance y
// mspeed = movement speed of the player
// rspeed = rotation speed of the player
// cx = fov_ratio
typedef struct s_raycaster_data
{
	mlx_image_t		*background;
	mlx_image_t		*screen;
	mlx_image_t		*minimap;
	int				floor_color;
	int				ceiling_color;
	int				color;
	int				screen_width;
	int				screen_height;
	int				map_width;
	int				map_height;
	int				**map;
	int				tile_size;
	int				map_x;
	int				map_y;
	int				side;
	int				step_x;
	int				step_y;
	int				x;
	int				y;
	double			pa;
	double			px;
	double			py;
	double			pdx;
	double			pdy;
	double			cx;
	double			cpx;
	double			cpy;
	double			d_dist_x;
	double			d_dist_y;
	double			rx;
	double			ry;
	double			ra;
	double			rda;
	double			rdx;
	double			rdy;
	double			pwd;
	double			s_dist_x;
	double			s_dist_y;
	double			mspeed;
	double			rspeed;
	int				vertical_view;
	int				tex_x;
	int				tex_y;
	int				tex_num;
	int				draw_start;
	int				draw_end;
	int				line_height;
	double			tex_pos;
	double			tex_step;
	double			wall_x;
	t_point			old_block;
	t_point			new_block;
	mlx_t			*mlx;
	mlx_texture_t	*tex;
	mlx_texture_t	*textures[4];
}					t_raycaster_data;

#endif