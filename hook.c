/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:06:19 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/10 13:15:06 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_press(t_player *player)
{
	player->up = 0;
	player->down = 0;
	player->left = 0;
	player->right = 0;
	player->rot_left = 0;
	player->rot_right = 0;
}

int	close_win(t_data *data)
{
	mlx_destroy_image(data->mlx->ptr, data->mlx->img);
	mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	exit (0);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == 53)
		close_win(data);
	else if (key == 13)
		data->player->up = 1;
	else if (key == 1)
		data->player->down = 1;
	else if (key == 0)
		data->player->left = 1;
	else if (key == 2)
		data->player->right = 1;
	else if (key == 123)
		data->player->rot_left = 1;
	else if (key == 124)
		data->player->rot_right = 1;
	return (0);
}

int	handle_keyrelease(int key, t_data *data)
{
	if (key == 13)
		data->player->up = 0;
	else if (key == 1)
		data->player->down = 0;
	else if (key == 0)
		data->player->left = 0;
	else if (key == 2)
		data->player->right = 0;
	else if (key == 123)
		data->player->rot_left = 0;
	else if (key == 124)
		data->player->rot_right = 0;
	return (0);
}
