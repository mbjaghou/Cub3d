/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:02:32 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/07 11:48:38 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_fandl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '\t')
			return (1);
		i++;
	}
	return (0);
}

int	check_landr(char **str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i])
	{
		line = ft_strtrim(str[i], " \t");
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		{
			free(line);
			return (1);
		}
		free(line);
		i++;
	}
	return (0);
}

int	check_middel2(char **str, int i, int j)
{
	if (str[i][j - 1] == ' ' || str[i][j - 1] == '\t'
		|| str[i][j + 1] == ' ' || str[i][j + 1] == '\t')
		return (1);
	if ((int)ft_strlen(str[i - 1]) <= j || (int)ft_strlen(str[i + 1]) <= j)
		return (1);
	else if (str[i - 1][j] == ' ' || str[i - 1][j] == '\t'
		|| str[i + 1][j] == ' ' || str[i + 1][j] == '\t')
		return (1);
	return (0);
}

int	check_middel(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != ' ' && str[i][j] != '\t'
				&& str[i][j] != '1' && check_middel2(str, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_scene(t_data *data)
{
	int	l;

	l = 0;
	while (data->scene[l])
		l++;
	if (check_fandl(data->scene[0]) || check_fandl(data->scene[l - 1]))
	{
		print_error("Error\nMap does not close\n");
		return (1);
	}
	else if (check_landr(data->scene))
	{
		print_error("Error\nMap does not close\n");
		return (1);
	}
	else if (check_middel(data->scene))
	{
		printf("Error\nMap does not close\n");
		return (1);
	}
	return (0);
}
