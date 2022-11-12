/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:07:55 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/07 11:48:44 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free (str[i]);
		str[i] = NULL;
		i++;
	}
	if (str)
		free (str);
}

void	init_data(t_data *data)
{
	data->floor = -1;
	data->ceilling = -1;
	data->no = 0;
	data->we = 0;
	data->so = 0;
	data->ea = 0;
}

int	fill_path(char **str, t_data *data)
{
	if (str[1]
		&& !ft_strncmp(".xpm", str[1] + ft_strlen(str[1]) - 4, 4) && !str[2])
	{
		if (!data->no && !ft_strcmp(str[0], "NO"))
			data->no = ft_strdup(str[1]);
		else if (!data->so && !ft_strcmp(str[0], "SO"))
			data->so = ft_strdup(str[1]);
		else if (!data->we && !ft_strcmp(str[0], "WE"))
			data->we = ft_strdup(str[1]);
		else if (!data->ea && !ft_strcmp(str[0], "EA"))
			data->ea = ft_strdup(str[1]);
		else
		{
			print_error("Error\nSome textures are duplicated\n");
			return (1);
		}
	}
	else
	{
		print_error("Error\nXpm path\n");
		return (1);
	}
	return (0);
}

int	fill_data(char *line, t_data *data)
{
	char	**str;
	char	**colors;

	str = ft_split(line, " \t");
	if (str[0] && (!ft_strcmp(str[0], "NO") || !ft_strcmp(str[0], "SO")
			|| !ft_strcmp(str[0], "WE") || !ft_strcmp(str[0], "EA")))
	{
		if (fill_path(str, data))
			return (free_str(str), 1);
	}
	else if (str[0] && (!ft_strcmp(str[0], "F") || !ft_strcmp(str[0], "C")))
	{
		colors = join_color(str);
		if (!colors || check_color(colors))
		{
			print_error("Error\nInvalid rgb format\n");
			return (free_str(colors), free_str(str), 1);
		}
		if (fill_color(colors, data, str[0]))
			return (free_str(str), free_str(colors), 1);
		free_str(colors);
	}
	else if (str[0])
		return (free_str(str), 2);
	return (free_str(str), 0);
}
