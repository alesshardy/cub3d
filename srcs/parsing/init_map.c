/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:52:18 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 13:09:41 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_max_line_length(char **map)
{
	int	max_len;
	int	i;
	int	len;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		len = strlen(map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (max_len);
}

static void	change_void_in_wall(t_data *data, int max_len, int i)
{
	int	j;

	j = 0;
	while (j < max_len)
	{
		if (data->info.copy_map[i][j] == ' ')
			data->info.copy_map[i][j] = '1';
		j++;
	}
}

static void	make_map_rectangular(t_data *data)
{
	int		max_len;
	int		i;
	int		len;
	char	*new_line;

	i = 0;
	max_len = get_max_line_length(data->info.copy_map);
	while (data->info.copy_map[i])
	{
		len = strlen(data->info.copy_map[i]);
		if (len < max_len)
		{
			new_line = malloc(max_len + 1);
			if (!new_line)
				return ;
			ft_strcpy(new_line, data->info.copy_map[i]);
			ft_memset(new_line + len, '1', max_len - len);
			new_line[max_len] = '\0';
			free(data->info.copy_map[i]);
			data->info.copy_map[i] = new_line;
		}
		change_void_in_wall(data, max_len, i);
		i++;
	}
}

static void	get_map_width_height(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->mapwidth = 0;
	data->mapheight = 0;
	while (data->info.copy_map[i][j])
	{
		data->mapwidth++;
		j++;
	}
	while (data->info.copy_map[i])
	{
		data->mapheight++;
		i++;
	}
	data->tab_height = data->mapheight;
	data->tab_width = data->mapwidth;
}

void	init_map(t_data *data)
{
	make_map_rectangular(data);
	get_map_width_height(data);
}
