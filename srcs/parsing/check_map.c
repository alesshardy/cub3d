/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:52:50 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 13:19:03 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	other_caracter(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ' &&
				map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' &&
				map[i][j] != 'W')
			{
				printf("Error\nInvalid character in map or Island\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	handle_player_count(char **map, int height, t_data *data,
t_map_vars *vars)
{
	vars->player_count = 0;
	vars->i = 0;
	while (vars->i < height)
	{
		vars->j = 0;
		while (map[vars->i][vars->j])
		{
			if (map[vars->i][vars->j] == 'N' || map[vars->i][vars->j] == 'S' ||
				map[vars->i][vars->j] == 'E' || map[vars->i][vars->j] == 'W')
			{
				data->pos_x = vars->j;
				data->pos_y = vars->i;
				vars->player_count++;
			}
			vars->j++;
		}
		vars->i++;
	}
	if (vars->player_count != 1)
	{
		printf("Error\nThere must be exactly one player \
start position (N, S, E, W).\n");
		return (1);
	}
	return (0);
}

static int	check_hole(char **map, int height)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				flag = can_escape(map, i, j, height);
			if (flag)
			{
				printf("Error\nMap is not closed\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	validate_map(char **map, int height, t_data *data)
{
	t_map_vars	vars;

	vars.i = 0;
	if (check_hole(map, height))
		return (0);
	if (handle_player_count(map, height, data, &vars))
		return (0);
	if (other_caracter(map, height))
		return (0);
	return (1);
}

int	check_map(t_data *data)
{
	data->map = copy_map(data->info.copy_map, data);
	get_map_lenght_height(data);
	if (!validate_map(data->map, data->info.map_height, data))
		clean_exit(data, 1, 0);
	return (0);
}
