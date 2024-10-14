/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:43:19 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 13:00:54 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_ext_cub(char *str)
{
	if (str[0] == '.')
		return (1);
	while (*str != '.' && *str != '\0')
		str++;
	if (*str == '.')
	{
		str++;
		if (ft_strlen(str) == 3)
		{
			if (str[0] == 'c' && str[1] == 'u' && str[2] == 'b')
				return (0);
		}
	}
	return (1);
}

int	check_ext_xpm(char *str)
{
	if (str[0] != '.')
		return (1);
	str++;
	while (*str != '.' && *str != '\0')
		str++;
	if (*str == '.')
	{
		str++;
		if (ft_strlen(str) == 3)
		{
			if (str[0] == 'x' && str[1] == 'p' && str[2] == 'm')
				return (0);
		}
	}
	return (1);
}

static int	is_directory(char *str)
{
	int	fd;
	int	ret;

	ret = 0;
	fd = open(str, __O_DIRECTORY);
	if (fd > 0)
	{
		ret = 1;
		close(fd);
	}
	return (ret);
}

int	check_file(t_data *data, char *file_name)
{
	int	fd;

	if (is_directory(file_name))
		exit_read(data, "Error\nFile is a directory\n", 0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_read(data, "Error\nFile not found\n", 0);
	close(fd);
	return (0);
}
