/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:38:23 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 16:49:07 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_north_texture(char *str, int *i, t_data *data)
{
	char	*tmp;

	*i += 2;
	while (is_whitespace(str[*i]))
		(*i)++;
	if (data->info.n_flag == 1)
		exit_read(data, "Error\nDuplicate north texture\n", 0);
	tmp = ft_strdup(&str[*i]);
	if (tmp == NULL)
		exit_read(data, "Error\nMemory allocation failed\n", 0);
	trim_trailing_whitespace(tmp);
	data->info.north = tmp;
	data->info.n_flag = 1;
}

static void	get_south_texture(char *str, int *i, t_data *data)
{
	char	*tmp;

	*i += 2;
	while (is_whitespace(str[*i]))
		(*i)++;
	if (data->info.s_flag == 1)
		exit_read(data, "Error\nDuplicate south texture\n", 0);
	tmp = ft_strdup(&str[*i]);
	if (tmp == NULL)
		exit_read(data, "Error\nMemory allocation failed\n", 0);
	trim_trailing_whitespace(tmp);
	data->info.south = tmp;
	data->info.s_flag = 1;
}

static void	get_west_texture(char *str, int *i, t_data *data)
{
	char	*tmp;

	*i += 2;
	while (is_whitespace(str[*i]))
		(*i)++;
	if (data->info.w_flag == 1)
		exit_read(data, "Error\nDuplicate west texture\n", 0);
	tmp = ft_strdup(&str[*i]);
	if (tmp == NULL)
		exit_read(data, "Error\nMemory allocation failed\n", 0);
	trim_trailing_whitespace(tmp);
	data->info.west = tmp;
	data->info.w_flag = 1;
}

static void	get_east_texture(char *str, int *i, t_data *data)
{
	char	*tmp;

	*i += 2;
	while (is_whitespace(str[*i]))
		(*i)++;
	if (data->info.e_flag == 1)
		exit_read(data, "Error\nDuplicate east texture\n", 0);
	tmp = ft_strdup(&str[*i]);
	if (tmp == NULL)
		exit_read(data, "Error\nMemory allocation failed\n", 0);
	trim_trailing_whitespace(tmp);
	data->info.east = tmp;
	data->info.e_flag = 1;
}

void	get_texture(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == 'N' && str[i + 1] == 'O')
		get_north_texture(str, &i, data);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		get_south_texture(str, &i, data);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		get_west_texture(str, &i, data);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		get_east_texture(str, &i, data);
}
