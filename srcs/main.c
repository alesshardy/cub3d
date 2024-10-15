/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:13:25 by apintus           #+#    #+#             */
/*   Updated: 2024/10/15 14:38:56 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parsing(t_data *data, int ac, char **av)
{
	if (ac != 2 || check_ext_cub(av[1]))
		return (free(data),
			ft_putstr_fd("Error\nInvalid argument or file extension\n", 2), 1);
	init_data(data);
	if (check_file(data, av[1]))
		return (free(data), 1);
	copy_file(data, av[1]);
	get_info(data->info.file, data);
	check_map(data);
	init_game(data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (exit_read(data, "Error\nFailed to initialize MLX\n", 0), 1);
	if (init_texture(data) == 1)
		return (exit_read(data, "Error\nFailed to initialize textures\n", 1), 1);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"CIRCUSMAXIMUS");
	if (data->win == NULL)
		return (exit_read(data, "Error\nFailed to create window\n", 1), 1);
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_height);
	if (data->img == NULL)
		return (exit_read(data, "Error\nFailed to create image\n", 1), 1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	return (0);
}

static void	game(t_data *data)
{
	mlx_loop_hook(data->mlx, execute_raycasting, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->win, 17, 1L << 17, close_game, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (ft_putstr_fd("Error\nMemory allocation failed\n", 2), 1);
	if (parsing(data, ac, av) == 1)
		return (1);
	game(data);
	clean_exit(data, 0, 0);
	return (0);
}
