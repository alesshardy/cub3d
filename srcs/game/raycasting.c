/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:43:00 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 17:26:23 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_collisions(t_data *data)
{
	t_vector2_d	origin;
	t_vector2_d	res;
	int			i;

	origin.x = data->player.pos.x;
	origin.y = data->player.pos.y;
	i = 0;
	while (i < data->ray_count)
	{
		res = dda(data, &data->ray_array[i]);
		if (res.x != -1 && res.y != -1)
		{
			data->ray_array[i].hit_point = res;
			data->ray_array[i].len = get_vector_double_len(origin, res);
		}
		else
			data->ray_array[i].len = -1;
		i++;
	}
}

static void	generate_rays(t_data *data)
{
	t_ray_create_vars	v;

	v.origin.x = data->player.pos.x;
	v.origin.y = data->player.pos.y;
	v.angle = atan2(data->player.dir.y, data->player.dir.x);
	v.view_dst_pos.x = v.origin.x + data->player.dir.x * data->view_dst;
	v.view_dst_pos.y = v.origin.y + data->player.dir.y * data->view_dst;
	v.opp_len = tan(degree_to_radian(FOV_ANGLE / 2)) * data->view_dst;
	v.opp_vec[0] = create_vector_d_from_origin(v.view_dst_pos, v.angle
			+ M_PI / 2, v.opp_len);
	v.opp_vec[1] = create_vector_d_from_origin(v.view_dst_pos, v.angle
			- M_PI / 2, v.opp_len);
	v.increm = 1.0f / (data->ray_count - 1.0f);
	v.i = 0;
	while (v.i < data->ray_count)
	{
		v.vec = vector_d_lerp(v.opp_vec[0], v.opp_vec[1], v.increm * v.i);
		data->ray_array[v.i].angle = get_angle(v.origin, v.vec.x, v.vec.y);
		data->ray_array[v.i].hit_point = v.vec;
		data->ray_array[v.i].hit_point.y = data->tab_height * data->cell_size
			- data->ray_array[v.i].hit_point.y;
		v.i++;
	}
}

int	execute_raycasting(t_data *data)
{
	input_key(data);
	floor_and_ceiling(data);
	generate_rays(data);
	calculate_collisions(data);
	draw_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
