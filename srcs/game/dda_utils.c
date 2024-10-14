/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:36:08 by kammi             #+#    #+#             */
/*   Updated: 2024/10/11 13:12:34 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_initial_distances2(t_dda_vars *v)
{
	if (v->dir.x < 0)
	{
		v->step.x = -1;
		v->side_dist.x = (v->origin.x - v->map.x) * v->delta_dist.x;
	}
	else
	{
		v->step.x = 1;
		v->side_dist.x = (v->map.x + 1.0f - v->origin.x) * v->delta_dist.x;
	}
	if (v->dir.y < 0)
	{
		v->step.y = -1;
		v->side_dist.y = (v->origin.y - v->map.y) * v->delta_dist.y;
	}
	else
	{
		v->step.y = 1;
		v->side_dist.y = (v->map.y + 1.0f - v->origin.y) * v->delta_dist.y;
	}
}

void	calculate_initial_distances(t_dda_vars *v)
{
	if (v->dir.x == 0)
		v->delta_dist.x = 1e30;
	else
		v->delta_dist.x = fabs(1.0f / v->dir.x);
	if (v->dir.y == 0)
		v->delta_dist.y = 1e30;
	else
		v->delta_dist.y = fabs(1.0f / v->dir.y);
	calculate_initial_distances2(v);
}

void	initialize_dda_vars(t_data *data, t_ray *ray, t_dda_vars *v)
{
	v->origin.x = (double)data->player.pos.x;
	v->origin.y = (double)data->player.pos.y;
	v->map = v->origin;
	v->dir.x = ray->hit_point.x - v->origin.x;
	v->dir.y = ray->hit_point.y - v->origin.y;
}
