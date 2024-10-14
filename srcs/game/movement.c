/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:15:09 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 13:14:15 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rotate_left(t_data *data)
{
	double	rot_speed;
	double	old_dir_x;

	rot_speed = ROTATE_SPEED;
	old_dir_x = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(-rot_speed)
		- data->player.dir.y * sin(-rot_speed);
	data->player.dir.y = old_dir_x * sin(-rot_speed)
		+ data->player.dir.y * cos(-rot_speed);
	return (0);
}

static int	rotate_right(t_data *data)
{
	double	rot_speed;
	double	old_dir_x;

	rot_speed = ROTATE_SPEED;
	old_dir_x = data->player.dir.x;
	data->player.dir.x = data->player.dir.x * cos(rot_speed)
		- data->player.dir.y * sin(rot_speed);
	data->player.dir.y = old_dir_x * sin(rot_speed)
		+ data->player.dir.y * cos(rot_speed);
	return (0);
}

int	is_colliding(t_data *data, float x, float y)
{
	t_vector2_d	cell;
	float		margin;
	float		corners[4][2];
	int			i;

	margin = 3.0;
	corners[0][0] = x - margin;
	corners[0][1] = y - margin;
	corners[1][0] = x + margin;
	corners[1][1] = y - margin;
	corners[2][0] = x - margin;
	corners[2][1] = y + margin;
	corners[3][0] = x + margin;
	corners[3][1] = y + margin;
	i = 0;
	while (i < 4)
	{
		cell.x = corners[i][0] / data->cell_size;
		cell.y = corners[i][1] / data->cell_size;
		if (data->tab[(int)cell.y][(int)cell.x] == 1)
			return (1);
		i++;
	}
	return (0);
}

// Arrow keys are reversed for 3d render
int	input_key(t_data *data)
{
	if (data->keyboard[202])
		rotate_left(data);
	if (data->keyboard[201])
		rotate_right(data);
	if (data->keyboard[KEY_W])
		move_forward(data);
	if (data->keyboard[KEY_S])
		move_backward(data);
	if (data->keyboard[KEY_A])
		move_left(data);
	if (data->keyboard[KEY_D])
		move_right(data);
	data->player.view_dis_pos.x = data->player.dir.x * data->view_dst
		+ data->player.pos.x;
	data->player.view_dis_pos.y = data->player.dir.y * data->view_dst
		+ data->player.pos.y;
	return (0);
}
