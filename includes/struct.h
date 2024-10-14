/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:13:53 by kammi             #+#    #+#             */
/*   Updated: 2024/10/14 12:19:52 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_file
{
	char	**file;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor[3];
	int		celling[3];
	char	**copy_map;
	int		map_height;
	int		map_lenght;
	int		n_flag;
	int		s_flag;
	int		e_flag;
	int		w_flag;
	int		f_flag;
	int		c_flag;
}	t_file;

typedef struct s_text
{
	void	*img;
	char	*text_addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		width_img;
	int		height_img;
}	t_text;

typedef struct s_vector2_i
{
	int	x;
	int	y;
}	t_vector2_i;

typedef struct s_vector2_d
{
	double	x;
	double	y;
}	t_vector2_d;

typedef struct s_vector2_f
{
	float	x;
	float	y;
}	t_vector2_f;

typedef struct s_ray
{
	t_vector2_f	hit_point_f;
	t_vector2_d	hit_point;
	t_vector2_d	cell;
	double		len;
	int			side_hit;
	double		angle;
	double		perp_len;
}	t_ray;

typedef struct s_player
{
	t_vector2_f	pos;
	t_vector2_d	view_dis_pos;
	t_vector2_f	dir;
}	t_player;

// VARS STRUCT FOR NORM
typedef struct s_map_vars
{
	int	i;
	int	j;
	int	k;
	int	len_curr;
	int	len_top;
	int	len_bottom;
	int	player_count;
}	t_map_vars;

// VARS STRUCT FOR NORM
typedef struct s_flo_cel_vars
{
	int		floor_color;
	int		ceiling_color;
	int		half_height;
	int		*buffer;
	int		y;
	int		x;
}	t_flo_cel_vars;

// VARS STRUCT FOR NORM
typedef struct s_ray_render_vars
{
	int			i;
	int			y;
	float		slice_height;
	t_ray		*ray;
	t_vector2_d	tl;
	t_vector2_d	br;
	t_text		*texture;
	int			tex_x;
	double		tex_y;
	double		step;
	int			color;
	int			x;
}	t_ray_render_vars;

// VARS STRUCT FOR NORM
typedef struct s_dda_vars
{
	t_vector2_d	origin;
	t_vector2_d	map;
	t_vector2_d	dir;
	t_vector2_d	side_dist;
	t_vector2_d	delta_dist;
	t_vector2_d	step;
	t_vector2_i	cell;
	t_vector2_d	hit_point;
	double		ray_length;
}	t_dda_vars;

// VARS STRUCT FOR NORM
typedef struct s_ray_create_vars
{
	t_vector2_d	origin;
	double		angle;
	t_vector2_d	view_dst_pos;
	int			opp_len;
	t_vector2_d	opp_vec[2];
	double		increm;
	int			i;
	t_vector2_d	vec;
}	t_ray_create_vars;

// MAIN STRUCTURE
typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*win2;
	int			win_height;
	int			win_width;
	t_file		info;
	char		**map;
	char		*bigline;
	float		pos_x;
	float		pos_y;
	int			mapheight;
	int			mapwidth;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*img2;
	char		*addr2;
	int			bits_per_pixel2;
	int			line_length2;
	int			endian2;
	int			keyboard[203];
	int			mouse_button;
	int			mouse_x;
	int			mouse_y;
	int			**tab;
	int			tab_width;
	int			tab_height;
	int			cell_size;
	t_ray		*ray_array;
	int			ray_count;
	int			view_dst;
	float		*ray_angles;
	t_player	player;
	t_text		text[4];
}	t_data;

#endif
