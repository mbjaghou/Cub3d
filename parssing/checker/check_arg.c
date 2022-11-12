/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:11:59 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/10 13:12:41 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	fill_map(char *str, t_data *data)
{
	int	i;
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		print_error("Error\nfile: No such file or directory\n");
		return (1);
	}
	data->map = (char **)malloc(sizeof(char *) * (data->len + 1));
	if (!data->map)
	{
		print_error("Error\nmalloc: Out of memory\n");
		return (1);
	}
	i = -1;
	while (++i < data->len)
		data->map[i] = get_next_line(fd);
	data->map[i] = NULL;
	if (close(fd) == -1)
		exit (0);
	return (0);
}

int	get_len(int fd)
{
	char	*line;
	int		len;

	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	return (len);
}

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
}

int	checker(int ac, char **av, t_data *data)
{
	int	fd;

	if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
	{
		print_error("Error\nusage: cub3D <filename>.cub\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Error\nfile: No such file or directory\n");
		return (1);
	}
	data->len = get_len(fd);
	if (data->len == 0)
	{
		print_error("Error\nfile: file is empty\n");
		close(fd);
		return (1);
	}
	if (close(fd) == -1)
		exit (0);
	if (fill_map(av[1], data))
		return (1);
	return (0);
}
