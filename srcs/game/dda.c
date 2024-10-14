/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:35:44 by kammi             #+#    #+#             */
/*   Updated: 2024/10/11 13:13:39 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	update_side_dist_x(t_data *data, t_ray *ray, t_dda_vars *v)
{
	v->side_dist.x += v->delta_dist.x;
	v->map.x += v->step.x;
	ray->perp_len = (v->side_dist.x - v->delta_dist.x) * data->cell_size;
	if (v->step.x > 0)
		ray->side_hit = 2;
	else
		ray->side_hit = 3;
}

static void	update_side_dist_y(t_data *data, t_ray *ray, t_dda_vars *v)
{
	v->side_dist.y += v->delta_dist.y;
	v->map.y += v->step.y;
	ray->perp_len = (v->side_dist.y - v->delta_dist.y) * data->cell_size;
	if (v->step.y > 0)
		ray->side_hit = 0;
	else
		ray->side_hit = 1;
}

static t_vector2_d	calculate_hit_point(t_ray *ray, t_dda_vars *v)
{
	if (ray->side_hit == 2 || ray->side_hit == 3)
	{
		v->hit_point.x = v->map.x;
		v->hit_point.y = v->origin.y + (v->map.x - v->origin.x)
			* (v->dir.y / v->dir.x);
	}
	else
	{
		v->hit_point.x = v->origin.x + (v->map.y - v->origin.y)
			* (v->dir.x / v->dir.y);
		v->hit_point.y = v->map.y;
	}
	return (v->hit_point);
}

static t_vector2_d	perform_dda(t_data *data, t_ray *ray, t_dda_vars *v)
{
	v->ray_length = get_vector_double_len(v->origin, v->map);
	while (v->ray_length < data->view_dst * data->view_dst)
	{
		if (v->side_dist.x < v->side_dist.y)
			update_side_dist_x(data, ray, v);
		else
			update_side_dist_y(data, ray, v);
		v->ray_length = get_vector_double_len(v->origin, v->map);
		v->cell.x = v->map.x / data->cell_size;
		v->cell.y = v->map.y / data->cell_size;
		if (v->cell.x < 0 || v->cell.x >= data->win_width || v->cell.y < 0
			|| v->cell.y >= data->win_height)
			continue ;
		if (data->tab[v->cell.y][v->cell.x] == 1)
			return (calculate_hit_point(ray, v));
	}
	return (v->map);
}

t_vector2_d	dda(t_data *data, t_ray *ray)
{
	t_dda_vars	v;

	initialize_dda_vars(data, ray, &v);
	calculate_initial_distances(&v);
	return (perform_dda(data, ray, &v));
}
