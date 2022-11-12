/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <yachehbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:03:22 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/06 14:51:24 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_pos(t_data *data)
{
	if (data->player->up == 1)
		move_up(data);
	if (data->player->down == 1)
		move_down(data);
	if (data->player->left == 1)
		move_left(data);
	if (data->player->right == 1)
		move_right(data);
	if (data->player->rot_left == 1)
		data->player->dir -= SPEED;
	if (data->player->rot_right == 1)
		data->player->dir += SPEED;
}

int	update(void *v_data)
{
	t_data	*data;

	data = (t_data *)v_data;
	update_player_pos(data);
	ray_cast(data, data->player);
	mlx_put_image_to_window(data->mlx->ptr, data->mlx->win,
		data->mlx->img, 0, 0);
	return (0);
}
