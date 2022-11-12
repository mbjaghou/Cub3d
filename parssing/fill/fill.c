/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:07:57 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/07 11:48:48 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_map2(char c)
{
	if (c != '1' && c != '0' && c != 'N'
		&& c != 'S' && c != 'E' && c != 'W'
		&& c != '\n' && c != ' ' && c != '\t')
	{
		print_error("Error\nInvalid character in map\n");
		return (1);
	}
	return (0);
}

int	check_map(char **map, int i)
{
	int	j;
	int	nb_player;

	nb_player = 0;
	while (map[i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (check_map2(map[i][j]))
				return (1);
			else if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				nb_player++;
		}
		i++;
	}
	if (nb_player != 1)
	{
		print_error("Error\nNeed just one player\n");
		return (1);
	}
	return (0);
}

int	fill(t_data *data, int i, int j)
{
	char	*line;

	while (++i < data->len)
	{
		line = ft_strtrim(data->map[i], "\n");
		j = fill_data(line, data);
		free(line);
		if (j == 1)
			return (1);
		else if (j == 2)
			break ;
	}
	if (check_map(data->map, i))
		return (1);
	j = i;
	while (i < data->len)
	{
		line = ft_strtrim(data->map[i], "\n");
		if (!line[0])
			break ;
		free(line);
		i++;
	}
	fill_scene(data, j, i);
	return (free_str(data->map), 0);
}
