/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kammi <kammi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:15:54 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 12:12:00 by kammi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3d.h"

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	trim_trailing_whitespace(char *str)
{
	int	len;

	len = strlen(str);
	while (len > 0 && is_whitespace((unsigned char)str[len - 1]))
	{
		str[len - 1] = '\0';
		len--;
	}
}

void	get_map(char **file_copy, int i, t_data *data)
{
	int	j;
	int	len;

	j = 0;
	check_before_map(data);
	len = ft_tablen(file_copy);
	data->info.copy_map = malloc(sizeof(char *) * (len - i + 1));
	if (data->info.copy_map == NULL)
		exit_read(data, "Error\nMalloc error\n", 0);
	while (file_copy[i] != NULL)
	{
		data->info.copy_map[j] = ft_strdup(file_copy[i]);
		i++;
		j++;
	}
	data->info.copy_map[j] = NULL;
}

int	get_info(char **file_copy, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (file_copy[++i] != NULL)
	{
		j = 0;
		while (is_whitespace(file_copy[i][j]))
			j++;
		if ((file_copy[i][j] == 'N' && file_copy[i][j + 1] == 'O') ||
			(file_copy[i][j] == 'S' && file_copy[i][j + 1] == 'O') ||
			(file_copy[i][j] == 'W' && file_copy[i][j + 1] == 'E') ||
			(file_copy[i][j] == 'E' && file_copy[i][j + 1] == 'A'))
			get_texture(file_copy[i], data);
		else if (file_copy[i][j] == 'F' || file_copy[i][j] == 'C')
			get_color(file_copy[i], data);
		else if (file_copy[i][j] == '1')
		{
			get_map(file_copy, i, data);
			break ;
		}
		else if (file_copy[i][j] != '\0')
			exit_read(data, "Error\nWrong info\n", 0);
	}
	return (0);
}
