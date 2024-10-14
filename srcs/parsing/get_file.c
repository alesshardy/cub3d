/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:38:40 by apintus           #+#    #+#             */
/*   Updated: 2024/10/11 13:06:53 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_strdup_n(const char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (s[i] == '\n' && i == len - 1)
			str[i] = '\0';
		else
			str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	count_lines( char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd, 0);
	}
	close(fd);
	return (lines);
}

static void	read_and_copy_lines(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd, 0);
	while (line != NULL)
	{
		if (line[0] == '\n')
			data->info.file[i] = ft_strdup("\n");
		else
			data->info.file[i] = ft_strdup_n(line);
		if (data->info.file[i] == NULL)
			exit_read(data, "Error\nMalloc error\n", 0);
		free(line);
		i++;
		line = get_next_line(fd, 0);
	}
	data->info.file[i] = NULL;
}

int	copy_file(t_data *data, char *filename)
{
	int	fd;
	int	line_count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_read(data, "Error\nFile not found\n", 0);
	line_count = count_lines(filename);
	if (line_count < 0)
		exit_read(data, "Error\nCould not count lines\n", 0);
	data->info.file = malloc((line_count + 1) * sizeof(char *));
	if (data->info.file == NULL)
		exit_read(data, "Error\nMalloc error\n", 0);
	read_and_copy_lines(data, fd);
	close(fd);
	return (1);
}
