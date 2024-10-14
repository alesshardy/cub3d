/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:00:39 by kammi             #+#    #+#             */
/*   Updated: 2024/10/11 13:00:26 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_right(char **map, int i, int j)
{
	while (map[i][j])
	{
		if (map[i][j] == '1')
			return (1);
		j++;
	}
	return (0);
}

static int	check_down(char **map, int i, int j, int height)
{
	while (i < height)
	{
		if (map[i][j] == '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_left(char **map, int i, int j)
{
	while (j >= 0)
	{
		if (map[i][j] == '1')
			return (1);
		j--;
	}
	return (0);
}

static int	check_up(char **map, int i, int j)
{
	while (i >= 0)
	{
		if (map[i][j] == '1')
			return (1);
		i--;
	}
	return (0);
}

int	can_escape(char **map, int i, int j, int height)
{
	int	flag;

	flag = 0;
	flag += check_right(map, i, j);
	flag += check_down(map, i, j, height);
	flag += check_left(map, i, j);
	flag += check_up(map, i, j);
	if (flag == 4)
		return (0);
	return (1);
}
