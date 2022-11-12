/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <yachehbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:04:37 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/07 08:52:55 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	iswall(t_data *data, double x, double y)
{
	if (data->scene[(int)(y + 0.1)][(int)x] == '1'
		|| data->scene[(int)y][(int)(x + 0.1)] == '1'
		|| data->scene[(int)(y - 0.1)][(int)x] == '1'
		|| data->scene[(int)y][(int)(x - 0.1)] == '1')
		return (1);
	return (0);
}

void	move_up(t_data *data)
{
	double	n_dx;
	double	n_dy;

	n_dx = data->player->dx + cos(data->player->dir) * SPEED;
	n_dy = data->player->dy + sin(data->player->dir) * SPEED;
	if (!iswall(data, n_dx, n_dy))
	{	
		data->player->dx = n_dx;
		data->player->dy = n_dy;
	}
}

void	move_down(t_data *data)
{
	double	n_dx;
	double	n_dy;

	n_dx = data->player->dx - cos(data->player->dir) * SPEED;
	n_dy = data->player->dy - sin(data->player->dir) * SPEED;
	if (!iswall(data, n_dx, n_dy))
	{
		data->player->dx = n_dx;
		data->player->dy = n_dy;
	}
}

void	move_left(t_data *data)
{
	double	n_dx;
	double	n_dy;

	n_dx = data->player->dx + (cos(data->player->dir - M_PI_2)) * SPEED;
	n_dy = data->player->dy + (sin(data->player->dir - M_PI_2)) * SPEED;
	if (!iswall(data, (int)n_dx, (int)n_dy))
	{		
		data->player->dx = n_dx;
		data->player->dy = n_dy;
	}
}

void	move_right(t_data *data)
{
	double	n_dx;
	double	n_dy;

	n_dx = data->player->dx + (cos(data->player->dir + M_PI_2)) * SPEED;
	n_dy = data->player->dy + (sin(data->player->dir + M_PI_2)) * SPEED;
	if (!iswall(data, (int)n_dx, (int)n_dy))
	{		
		data->player->dx = n_dx;
		data->player->dy = n_dy;
	}
}
