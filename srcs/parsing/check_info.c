/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:46:56 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 18:06:52 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	second_check(t_data *data)
{
	if (check_ext_xpm(data->info.north) == 1)
		exit_read(data, "Error\nNorth texture is not an xpm file\n", 0);
	if (check_ext_xpm(data->info.south) == 1)
		exit_read(data, "Error\nSouth texture is not an xpm file\n", 0);
	if (check_ext_xpm(data->info.east) == 1)
		exit_read(data, "Error\nEast texture is not an xpm file\n", 0);
	if (check_ext_xpm(data->info.west) == 1)
		exit_read(data, "Error\nWest texture is not an xpm file\n", 0);
	if (data->info.floor[0] < 0 || data->info.floor[0] > 255
		|| data->info.floor[1] < 0 || data->info.floor[1] > 255
		|| data->info.floor[2] < 0 || data->info.floor[2] > 255)
		exit_read(data, "Error\nFloor color is not valid\n", 0);
	if (data->info.celling[0] < 0 || data->info.celling[0] > 255
		|| data->info.celling[1] < 0 || data->info.celling[1] > 255
		|| data->info.celling[2] < 0 || data->info.celling[2] > 255)
		exit_read(data, "Error\nCeiling color is not valid\n", 0);
	return (0);
}

int	check_before_map(t_data *data)
{
	if (data->info.north == NULL || data->info.south == NULL
		|| data->info.east == NULL || data->info.west == NULL)
		exit_read(data, "Error\nThe map description must always\
be at the end of the file\n", 0);
	if (data->info.floor[0] == -1 || data->info.floor[1] == -1
		|| data->info.floor[2] == -1 || data->info.celling[0] == -1
		|| data->info.celling[1] == -1 || data->info.celling[2] == -1)
		exit_read(data, "Error\nThe map description must always\
be at the end of the file\n", 0);
	second_check(data);
	return (0);
}
