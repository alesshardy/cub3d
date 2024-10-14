/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:21:54 by kammi             #+#    #+#             */
/*   Updated: 2024/10/11 16:53:22 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	onlywhitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

void	get_map_lenght_height(t_data *data)
{
	int	i;
	int	j;
	int	height;

	i = 0;
	height = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j > data->info.map_lenght)
			data->info.map_lenght = j;
		if (data->map[i][0] != '\n' && !onlywhitespace(data->map[i]))
			height++;
		i++;
	}
	data->info.map_height = height;
}

static void	copy_map_line(char **copy_map, char **map, int i, t_data *data)
{
	int	j;

	j = 0;
	copy_map[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
	if (copy_map[i] == NULL)
		exit_read(data, "Error\nMemory allocation failed\n", 0);
	while (map[i][j])
	{
		copy_map[i][j] = map[i][j];
		if (map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'W' || map[i][j] == 'E')
		{
			data->pos_x = j;
			data->pos_y = i;
		}
		j++;
	}
	copy_map[i][j] = '\0';
}

char	**copy_map(char **map, t_data *data)
{
	char	**copy_map;
	int		i;
	int		len;

	len = ft_tablen(map);
	if (len == 0)
		exit_read(data, "Error\n Empty map\n", 0);
	copy_map = malloc(sizeof(char *) * (len + 1));
	if (copy_map == NULL)
		exit_read(data, "Error\nMemory allocation failed\n", 0);
	i = 0;
	while (i < len)
	{
		copy_map_line(copy_map, map, i, data);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}
