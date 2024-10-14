/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:52:32 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 16:45:19 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"

static int	parse_color_component(char *str, int *i, long *temp)
{
	int	k;

	k = 0;
	if (!ft_isdigit(str[*i]) && !is_whitespace(str[*i]))
		return (-1);
	if ((str[*i] >= '0' && str[*i] <= '9'))
	{
		*temp = ft_atoi(&str[*i]);
		if (*temp > INT_MAX)
			return (-1);
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			(*i)++;
			k++;
			if (k > 10)
				return (-1);
		}
	}
	else
		(*i)++;
	return (0);
}

static int	validate_color_string(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (-1);
		i++;
	}
	return (0);
}

static void	set_color(int flag, int *color, t_data *data)
{
	if (flag == 'F')
	{
		if (data->info.f_flag == 1)
			exit_read(data, "Error\nDuplicate floor color\n", 0);
		data->info.floor[0] = color[0];
		data->info.floor[1] = color[1];
		data->info.floor[2] = color[2];
		data->info.f_flag = 1;
	}
	else if (flag == 'C')
	{
		if (data->info.c_flag == 1)
			exit_read(data, "Error\nDuplicate ceiling color\n", 0);
		data->info.celling[0] = color[0];
		data->info.celling[1] = color[1];
		data->info.celling[2] = color[2];
		data->info.c_flag = 1;
	}
}

static int	extract_colors(char *str, int *color)
{
	int		i;
	int		j;
	long	temp;

	i = 0;
	j = 0;
	while (str[i] != '\0' && j < 3)
	{
		while (is_whitespace(str[i]))
			i++;
		if ((j == 1 || j == 2) && str[i] != ',')
			return (-1);
		if ((j == 1 || j == 2) && str[i] == ',')
			i++;
		while (is_whitespace(str[i]))
			i++;
		if (parse_color_component(str, &i, &temp) == -1)
			return (-1);
		color[j] = (int)temp;
		j++;
	}
	if (validate_color_string(str, i) == -1)
		return (-1);
	return (j);
}

void	get_color(char *str, t_data *data)
{
	int	i;
	int	color[3];
	int	flag;
	int	num_colors;

	i = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == 'F' || str[i] == 'C')
	{
		flag = str[i];
		i++;
		while (is_whitespace(str[i]))
			i++;
		num_colors = extract_colors(&str[i], color);
		if (num_colors != 3 || num_colors == -1)
		{
			exit_read(data, "Error\nInvalid color code\n", 0);
			return ;
		}
		set_color(flag, color, data);
	}
}
