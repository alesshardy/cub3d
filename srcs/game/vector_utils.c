/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:11:17 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 12:13:32 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_angle(t_vector2_d origin, int x, int y)
{
	double	angle;
	double	dx;
	double	dy;

	dx = x - origin.x;
	dy = y - origin.y;
	angle = atan2(dy, dx);
	return (angle);
}

double	degree_to_radian(double degree)
{
	return (degree * PI / 180);
}

t_vector2_d	vector_d_lerp(t_vector2_d a, t_vector2_d b, double t)
{
	t_vector2_d	v;

	v.x = a.x + (b.x - a.x) * t;
	v.y = a.y + (b.y - a.y) * t;
	return (v);
}

double	get_vector_double_len(t_vector2_d origin, t_vector2_d dst)
{
	double	dx;
	double	dy;

	dx = dst.x - origin.x;
	dy = dst.y - origin.y;
	return (sqrt(dx * dx + dy * dy));
}

t_vector2_d	create_vector_d_from_origin(t_vector2_d origin, double angle
, int len)
{
	t_vector2_d	v;

	v.x = origin.x + len * cos(angle);
	v.y = origin.y + len * sin(angle);
	return (v);
}
