/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:54:36 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 17:32:32 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	render_column(t_data *data, t_ray_render_vars *v)
{
	while (v->y < v->br.y)
	{
		if (v->y >= 0 && v->y < data->win_height)
		{
			v->color = get_texture_pixel(v->texture, v->tex_x, v->tex_y);
			v->x = v->tl.x;
			while (v->x < v->br.x)
			{
				ft_mlx_pixel_put(data, v->x, v->y, v->color);
				v->x++;
			}
		}
		v->tex_y += v->step;
		v->y++;
	}
}

static void	render_single_ray(t_data *data, t_ray *ray, int i, int slice_width)
{
	t_ray_render_vars	v;

	v.slice_height = (float)(data->win_height / ray->perp_len);
	v.tl.x = i * slice_width;
	v.tl.y = data->win_height / 2 - v.slice_height / 2;
	v.br.x = i * slice_width + slice_width;
	v.br.y = data->win_height / 2 + v.slice_height / 2;
	v.texture = &data->text[ray->side_hit];
	v.tex_x = calculate_texture_x(data, ray, v.texture);
	v.tex_y = 0;
	v.step = v.texture->height_img / v.slice_height;
	v.y = v.tl.y;
	render_column(data, &v);
}

void	draw_rays(t_data *data)
{
	const int	slice_width = data->win_width / data->ray_count;
	int			i;
	t_ray		*ray;

	i = 0;
	while (i < data->ray_count)
	{
		ray = &data->ray_array[i];
		if (ray->len != -1)
			render_single_ray(data, ray, i, slice_width);
		i++;
	}
}
