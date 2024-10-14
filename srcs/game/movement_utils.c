/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:22:37 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 12:12:45 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(t_data *data)
{
	t_vector2_f	*p_pos;
	int			move_speed;

	p_pos = &data->player.pos;
	move_speed = MOVE_SPEED;
	if (!is_colliding(data, p_pos->x + data->player.dir.x * move_speed,
			p_pos->y))
		p_pos->x += data->player.dir.x * move_speed;
	if (!is_colliding(data, p_pos->x,
			p_pos->y - data->player.dir.y * move_speed))
		p_pos->y -= data->player.dir.y * move_speed;
	return (0);
}

int	move_backward(t_data *data)
{
	t_vector2_f	*p_pos;
	int			move_speed;

	p_pos = &data->player.pos;
	move_speed = MOVE_SPEED;
	if (!is_colliding(data, p_pos->x - data->player.dir.x * move_speed,
			p_pos->y))
		p_pos->x -= data->player.dir.x * move_speed;
	if (!is_colliding(data, p_pos->x,
			p_pos->y + data->player.dir.y * move_speed))
		p_pos->y += data->player.dir.y * move_speed;
	return (0);
}

int	move_left(t_data *data)
{
	t_vector2_f	*p_pos;
	int			move_speed;
	t_vector2_f	perp_dir;

	p_pos = &data->player.pos;
	move_speed = MOVE_SPEED;
	perp_dir.x = -data->player.dir.y;
	perp_dir.y = data->player.dir.x;
	if (!is_colliding(data, p_pos->x + perp_dir.x * move_speed, p_pos->y))
		p_pos->x += perp_dir.x * move_speed;
	if (!is_colliding(data, p_pos->x, p_pos->y - perp_dir.y * move_speed))
		p_pos->y -= perp_dir.y * move_speed;
	return (0);
}

int	move_right(t_data *data)
{
	t_vector2_f	*p_pos;
	int			move_speed;
	t_vector2_f	perp_dir;

	p_pos = &data->player.pos;
	move_speed = MOVE_SPEED;
	perp_dir.x = data->player.dir.y;
	perp_dir.y = -data->player.dir.x;
	if (!is_colliding(data, p_pos->x + perp_dir.x * move_speed, p_pos->y))
		p_pos->x += perp_dir.x * move_speed;
	if (!is_colliding(data, p_pos->x, p_pos->y - perp_dir.y * move_speed))
		p_pos->y -= perp_dir.y * move_speed;
	return (0);
}
