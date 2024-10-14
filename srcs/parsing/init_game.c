/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:33:30 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 16:49:33 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_tab(t_data *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	data->tab = malloc(sizeof(int *) * data->tab_height);
	if (data->tab == NULL)
		return (1);
	while (y < data->tab_height)
	{
		data->tab[y] = malloc(sizeof(int) * data->tab_width);
		if (data->tab[y] == NULL)
			return (1);
		x = 0;
		while (x < data->tab_width)
		{
			if (map[y][x] == '1')
				data->tab[y][x] = 1;
			else
				data->tab[y][x] = 0;
			x++;
		}
		y++;
	}
	return (0);
}

static void	init_rays(t_data *data)
{
	int		i;
	double	angle_step;

	i = 0;
	data->ray_count = RAY_COUNT;
	data->view_dst = RENDER_DISTANCE * data->cell_size;
	data->ray_array = malloc(sizeof(t_ray) * data->ray_count);
	if (data->ray_array == NULL)
		exit_read(data, "Error\nMemory allocation failed\n", 0);
	angle_step = FOV_ANGLE / data->ray_count;
	while (i < data->ray_count)
	{
		data->ray_array[i].angle = -FOV_ANGLE / 2 + i * angle_step;
		i++;
	}
	data->ray_angles = malloc(sizeof(float) * data->ray_count);
	if (data->ray_angles == NULL)
		exit_read(data, "Error\nMemory allocation failed\n", 0);
}

static void	init_player(t_data *data)
{
	data->player.pos.x = data->pos_x * data->cell_size + data->cell_size / 2;
	data->player.pos.y = data->pos_y * data->cell_size + data->cell_size / 2;
	if (data->info.copy_map[(int)data->pos_y][(int)data->pos_x] == 'N')
	{
		data->player.dir.x = 0;
		data->player.dir.y = 1;
	}
	else if (data->info.copy_map[(int)data->pos_y][(int)data->pos_x] == 'S')
	{
		data->player.dir.x = 0;
		data->player.dir.y = -1;
	}
	else if (data->info.copy_map[(int)data->pos_y][(int)data->pos_x] == 'E')
	{
		data->player.dir.x = 1;
		data->player.dir.y = 0;
	}
	else if (data->info.copy_map[(int)data->pos_y][(int)data->pos_x] == 'W')
	{
		data->player.dir.x = -1;
		data->player.dir.y = 0;
	}
}

static void	init_keyboard(int keyboard[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		keyboard[i] = 0;
		i++;
	}
}

void	init_game(t_data *data)
{
	init_map(data);
	init_rays(data);
	init_tab(data, data->info.copy_map);
	init_keyboard(data->keyboard, 203);
	init_player(data);
}
