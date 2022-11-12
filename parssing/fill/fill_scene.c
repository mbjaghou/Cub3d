/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:07:52 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/07 11:48:46 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	fill_scene(t_data *data, int f, int l)
{
	int	i;

	data->scene = malloc(sizeof(char *) * (l - f + 1));
	if (!data->scene)
	{
		free_str(data->map);
		print_error("Error\nMalloc : Out of memory\n");
		exit (0);
	}
	i = 0;
	while (f < l)
	{
		data->scene[i] = ft_strtrim(data->map[f], "\n");
		i++;
		f++;
	}
	data->scene[i] = NULL;
}
