/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:33:11 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/10 13:03:52 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_dir(char c, t_player *player)
{
	if (c == 'W')
		player->dir = 0;
	if (c == 'N')
		player->dir = M_PI_2;
	if (c == 'S')
		player->dir = 3 * M_PI_2;
	if (c == 'E')
		player->dir = M_PI;
}

void	init_player(t_data *data, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (data->scene[i])
	{
		j = 0;
		while (data->scene[i][j])
		{
			if (data->scene[i][j] == 'W' || data->scene[i][j] == 'N'
				|| data->scene[i][j] == 'S' || data->scene[i][j] == 'E')
			{
				player->x = j;
				player->y = i;
				player->dx = (double)j + 0.5;
				player->dy = (double)i + 0.5;
				init_player_dir(data->scene[i][j], player);
			}
			j++;
		}
		i++;
	}
	init_press(player);
}

int	txt_addr(t_mlx *mlx, t_data *data, char *path, int dir)
{
	data->txt[dir].img = mlx_xpm_file_to_image(mlx->ptr, path,
			&data->txt[dir].w, &data->txt[dir].h);
	if (!data->txt[dir].img)
		return (1);
	data->txt[dir].addr = mlx_get_data_addr(data->txt[dir].img,
			&data->txt[dir].bpp, &data->txt[dir].sl, &data->txt[dir].en);
	if (!data->txt[dir].addr)
		return (1);
	return (0);
}

int	init_txt(t_data *data, t_mlx *mlx)
{
	if (txt_addr(mlx, data, data->we, 0) || txt_addr(mlx, data, data->no, 1)
		|| txt_addr(mlx, data, data->ea, 2) || txt_addr(mlx, data, data->so, 3))
		return (1);
	return (0);
}

int	init(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	data->ray = malloc(sizeof(t_ray));
	data->player = malloc(sizeof(t_player));
	data->txt = malloc(sizeof(t_txt) * 4);
	if (!data->mlx || !data->ray || !data->player || !data->txt)
		return (1);
	data->mlx->ptr = mlx_init();
	if (!data->mlx->ptr)
		return (1);
	init_player(data, data->player);
	if (init_txt(data, data->mlx))
		return (1);
	data->mlx->win = mlx_new_window(data->mlx->ptr, WIN_W, WIN_H, "cub3D");
	if (!data->mlx->win)
		return (1);
	if (create_image(data, data->mlx))
		return (1);
	return (0);
}
