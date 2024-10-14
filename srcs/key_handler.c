/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:40:30 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 13:27:04 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode < 200)
		data->keyboard[keycode] = 1;
	if (keycode == XK_Escape)
		close_game(data);
	if (keycode == KEY_LEFT)
		data->keyboard[201] = 1;
	if (keycode == KEY_RIGHT)
		data->keyboard[202] = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode < 200)
		data->keyboard[keycode] = 0;
	if (keycode == KEY_LEFT)
		data->keyboard[201] = 0;
	if (keycode == KEY_RIGHT)
		data->keyboard[202] = 0;
	return (0);
}
