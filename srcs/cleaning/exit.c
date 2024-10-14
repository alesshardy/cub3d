/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:06:40 by apintus           #+#    #+#             */
/*   Updated: 2024/10/09 15:15:09 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_read(t_data *data, char *str, int flag)
{
	ft_putstr_fd(str, 2);
	clean_exit(data, 1, flag);
}

void	clean_exit(t_data *data, int exit_code, int flag)
{
	if (flag == 1)
		clean_mlx_loading_fail(data);
	clean_info(data);
	clean_map_and_copy(data);
	clean_ray_array(data);
	clean_tab(data);
	free(data);
	exit(exit_code);
}

int	close_game(t_data *data)
{
	clean_textures(data);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	clean_exit(data, 0, 0);
	return (0);
}
