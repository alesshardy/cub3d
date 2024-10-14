/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:24:59 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 12:54:00 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_texture(t_data *data)
{
	data->text[0].img = NULL;
	data->text[1].img = NULL;
	data->text[2].img = NULL;
	data->text[3].img = NULL;
	data->text[0].width_img = 0;
	data->text[1].width_img = 0;
	data->text[2].width_img = 0;
	data->text[3].width_img = 0;
	data->text[0].height_img = 0;
	data->text[1].height_img = 0;
	data->text[2].height_img = 0;
	data->text[3].height_img = 0;
	if (load_texture(data, &data->text[0], data->info.north) == 1)
		return (1);
	if (load_texture(data, &data->text[1], data->info.south) == 1)
		return (1);
	if (load_texture(data, &data->text[2], data->info.east) == 1)
		return (1);
	if (load_texture(data, &data->text[3], data->info.west) == 1)
		return (1);
	return (0);
}

static void	init_data2(t_data *data)
{
	data->pos_x = 0;
	data->pos_y = 0;
	data->info.n_flag = 0;
	data->info.s_flag = 0;
	data->info.e_flag = 0;
	data->info.w_flag = 0;
	data->info.f_flag = 0;
	data->info.c_flag = 0;
	data->cell_size = 64;
	data->win_height = 1080;
	data->win_width = 1920;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->ray_array = NULL;
	data->tab = NULL;
	data->ray_angles = NULL;
}

void	init_data(t_data *data)
{
	data->info.file = NULL;
	data->info.north = NULL;
	data->info.south = NULL;
	data->info.west = NULL;
	data->info.east = NULL;
	data->info.floor[0] = -1;
	data->info.floor[1] = -1;
	data->info.floor[2] = -1;
	data->info.celling[0] = -1;
	data->info.celling[1] = -1;
	data->info.celling[2] = -1;
	data->bigline = NULL;
	data->map = NULL;
	data->info.copy_map = NULL;
	data->info.map_height = 0;
	data->info.map_lenght = 0;
	init_data2(data);
}
