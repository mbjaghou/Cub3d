/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:06:30 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/07 11:48:40 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parssing(int ac, char **av, t_data *data)
{
	if (checker(ac, av, data))
		return (1);
	init_data(data);
	if (fill(data, -1, 0))
		return (1);
	if (check_scene(data))
		return (1);
	if (data->ceilling == -1 || data->floor == -1 || !data->we
		|| !data->ea || !data->so || !data->no)
	{
		print_error("Error\nMissing identifier\n");
		return (1);
	}
	return (0);
}
