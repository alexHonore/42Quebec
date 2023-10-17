/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anshimiy <anshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:26:12 by anshimiy          #+#    #+#             */
/*   Updated: 2023/10/12 19:17:12 by anshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

/* ****** INCLUDES ****** */

# include "MLX42/include/MLX42/MLX42.h"
# include "my_lib/mylib.h"
# include <complex.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include	<mlx.h>
# include "cub3d_struct_bonus.h"

/* ****************************** FUNCTIONS ****************************** */

/* ******   CUB3D   ****** */
void				cub3d(t_game_info *game_info);
void				remove_block(t_raycaster_data *rc);
void				move_block(t_raycaster_data *rc,
						t_point old_block, t_point new_block);
/* ******   RAYCASTING/INIT   ****** */
t_raycaster_data	init_raycaster_data(t_game_info *game_info);

/* ******   RAYCASTING/MOVEMENTS    ****** */
void				rotate_player(t_raycaster_data *rc, double rot);
int					block_forbidden(t_raycaster_data *rc,
						int to_remove_x, int to_remove_y);
/* ******   RAYCASTING   ****** */
void				raycast(t_raycaster_data *rc);

/* ******   RAYCASTING/WALL/DRAW   ****** */
void				prepare_for_drawing(t_raycaster_data *rc);
void				prepare_for_texture(t_raycaster_data *rc);
void				draw_textured_walls(t_raycaster_data *rc);

/* ******    PARSING/INIT    ****** */
t_game_info			*ft_init_game_info(char **argv);
void				ft_parse_infos(char *path, t_game_info *game_info);
void				ft_load_textures(char **file_data, t_game_info *game_info);
void				ft_load_map(char **file_data, t_game_info *game_info);
int					ft_get_color(char **strings, char *id);
void				ft_create_int_map(char **file_data, t_game_info *game_info);
int32_t				ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
/* ******     UTILS     ****** */
int					ft_find_map_position(char **file_data);
char				**ft_split_set(char *str, char *set);

/* ******     UTILS/DRAW     ****** */
void				lh_init(t_line_data *line_data, t_point *p1, t_point *p2);
t_rectangle			init_rectangle(int x, int y, int width, int height);
t_point				init_point(int x, int y);
void				set_background(t_raycaster_data rc);
void				draw_triangle(mlx_image_t *image, t_point points[3],
						uint32_t color);
void				draw_line(mlx_image_t *img, t_point p1, t_point p2,
						int color);
void				draw_rectangle(mlx_image_t *image, t_rectangle rec,
						uint32_t color);
void				draw_pointer(t_raycaster_data *rc);
/* ******   MINIMAP   ****** */
void				draw_map(t_raycaster_data rc);
/* ******   FLOOD FILL ALGO   ****** */
int					flood_check(char **file_data, t_game_info *game_info);
/* ******   RAYCASTING/UTILS   ****** */
void				key_hook(t_raycaster_data *rc);
t_rectangle			init_rectangle(int x, int y, int width, int height);
double				degree_to_radian(int a);
t_point				init_point(int x, int y);

/* ******     ERRORS     ****** */
void				ft_file_error_case(int error);
void				ft_map_error_case(int error);
void				ft_texture_error_case(int error);
void				ft_color_error_case(int error);

/* ******      MLX      ****** */
mlx_image_t			*new_image(mlx_t *mlx, int width, int height);
void				image_to_window(mlx_t *mlx, mlx_image_t *image, int x,
						int y);
void				put_pixel(mlx_image_t *image, int x, int y, uint32_t color);
mlx_texture_t		*load_png(char *path);

#endif