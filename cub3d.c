/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:00:40 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/10 13:01:48 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_data(t_data *data)
{
	free(data->mlx);
	free(data->txt);
	free(data->player);
	free(data->ray);
	free_str(data->scene);
	free(data->ea);
	free(data->we);
	free(data->no);
	free(data->so);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parssing(ac, av, &data))
		return (1);
	if (init(&data))
		return (1);
	mlx_hook(data.mlx->win, 17, 0, close_win, &data);
	mlx_hook(data.mlx->win, 2, 0, handle_keypress, &data);
	mlx_hook(data.mlx->win, 3, 0, handle_keyrelease, &data);
	mlx_loop_hook(data.mlx->ptr, update, &data);
	mlx_loop(data.mlx->ptr);
	free_data(&data);
	return (0);
}
