/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:49:39 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 17:30:46 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->text[i].img)
		{
			mlx_destroy_image(data->mlx, data->text[i].img);
		}
		i++;
	}
}

int	load_texture(t_data *data, t_text *text, char *path)
{
	text->img = mlx_xpm_file_to_image(data->mlx, path, &text->width_img,
			&text->height_img);
	if (text->img == NULL)
		return (1);
	text->text_addr = mlx_get_data_addr(text->img, &text->bits_per_pixel,
			&text->line_len, &text->endian);
	if (text->text_addr == NULL)
		return (1);
	return (0);
}

int	get_texture_pixel(t_text *text, int x, int y)
{
	int	color;

	if (x < 0 || x >= text->width_img)
		return (0);
	if (y < 0 || y >= text->height_img)
		return (0);
	color = *(int *)(text->text_addr + (y * text->line_len)
			+ (x * text->bits_per_pixel / 8));
	return (color);
}

int	calculate_texture_x(t_data *data, t_ray *ray, t_text *texture)
{
	double	wall_hit_x;
	int		tex_x;

	if (ray->side_hit == 0 || ray->side_hit == 1)
		wall_hit_x = fmod(ray->hit_point.x, data->cell_size) / data->cell_size;
	else
		wall_hit_x = fmod(ray->hit_point.y, data->cell_size) / data->cell_size;
	tex_x = (int)(wall_hit_x * (double)texture->width_img);
	if (ray->side_hit == 0)
		tex_x = texture->width_img - tex_x - 1;
	return (tex_x);
}
