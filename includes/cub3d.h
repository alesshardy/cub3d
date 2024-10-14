/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:13:36 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 18:03:57 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "define.h"
# include "struct.h"

// INIT DATA
void		init_data(t_data *data);
int			init_texture(t_data *data);

// PARSING
int			is_whitespace(char c);
int			check_ext_cub(char *str);
int			check_ext_xpm(char *str);
int			check_file(t_data *data, char *file_name);
int			copy_file(t_data *data, char *filename);
int			get_info(char **file_copy, t_data *data);
void		get_texture(char *str, t_data *data);
void		get_color(char *str, t_data *data);
int			check_before_map(t_data *data);
int			check_map(t_data *data);
int			ft_tablen(char **tab);
int			can_escape(char **map, int i, int j, int height);
char		**copy_map(char **map, t_data *data);
void		get_map_lenght_height(t_data *data);
void		trim_trailing_whitespace(char *str);

// INIT GAME
void		init_game(t_data *data);
int			init_texture(t_data *data);
void		init_map(t_data *data);

// RAYCASTING
int			execute_raycasting(t_data *data);
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
double		degree_to_radian(double degree);
void		draw_rays(t_data *data);

// VECTORS UTILS
double		get_angle(t_vector2_d origin, int x, int y);
double		degree_to_radian(double degree);
t_vector2_d	vector_d_lerp(t_vector2_d a, t_vector2_d b, double t);
double		get_vector_double_len(t_vector2_d origin, t_vector2_d dst);
t_vector2_d	create_vector_d_from_origin(t_vector2_d origin,
				double angle, int len);

// DDA
t_vector2_d	dda(t_data *data, t_ray *ray);
void		initialize_dda_vars(t_data *data, t_ray *ray, t_dda_vars *v);
void		calculate_initial_distances(t_dda_vars *v);

// COLORS UTILS
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void		floor_and_ceiling(t_data *data);
int			calculate_texture_x(t_data *data, t_ray *ray, t_text *texture);
int			get_texture_pixel(t_text *text, int x, int y);
int			load_texture(t_data *data, t_text *text, char *path);

// MOVEMENT
int			input_key(t_data *data);
int			move_forward(t_data *data);
int			move_backward(t_data *data);
int			move_left(t_data *data);
int			move_right(t_data *data);
int			is_colliding(t_data *data, float x, float y);
int			key_release(int keycode, t_data *data);
int			key_press(int keycode, t_data *data);

//CLEAN AND EXIT
void		exit_read(t_data *data, char *str, int flag);
void		clean_exit(t_data *data, int exit_code, int flag);
int			close_game(t_data *data);
void		clean_textures(t_data *data);
void		clean_mlx_loading_fail(t_data *data);
void		clean_info(t_data *data);
void		clean_ray_array(t_data *data);
void		clean_tab(t_data *data);
void		clean_map_and_copy(t_data *data);

#endif
