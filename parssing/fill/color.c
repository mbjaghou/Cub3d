/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:12:46 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/07 11:48:42 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_ver(char *color)
{
	int	i;

	if (color[0] == ',' || color[ft_strlen(color) - 1] == ',')
		return (1);
	i = 0;
	while (color[i])
	{
		if (color[i] == ',' && color[i + 1] && color[i + 1] == ',')
			return (1);
		i++;
	}
	return (0);
}

char	**join_color(char **str)
{
	char	*color;
	char	**colors;
	int		i;

	i = 0;
	color = ft_strdup("");
	while (str[++i])
		color = ft_strjoin(color, str[i]);
	if (check_ver(color))
	{
		free(color);
		return (NULL);
	}
	colors = ft_split(color, ",");
	free(color);
	return (colors);
}

int	check_color(char **colors)
{
	int	i;
	int	j;

	i = -1;
	while (colors[++i])
	{
		j = -1;
		while (colors[i][++j])
		{
			if (!ft_isdigit(colors[i][j]))
				return (1);
		}
	}
	i = -1;
	while (colors[++i])
	{
		if (ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
			return (1);
	}
	i = 0;
	while (colors[i])
		i++;
	if (i != 3)
		return (1);
	return (0);
}

int	fill_color(char **colors, t_data *data, char *str)
{
	int	color;

	color = ft_atoi(colors[0]) << 16
		| ft_atoi(colors[1]) << 8 | ft_atoi(colors[2]);
	if (data->floor == -1 && !ft_strcmp(str, "F"))
		data->floor = color;
	else if (data->ceilling == -1 && !ft_strcmp(str, "C"))
		data->ceilling = color;
	else
	{
		print_error("Error\nSome colors are duplicated\n");
		return (1);
	}
	return (0);
}
