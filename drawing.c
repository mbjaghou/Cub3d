/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:01:35 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/10 13:02:59 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_txt_color(t_txt *txt, int x, int y)
{
	int		color;
	char	*dst;

	dst = txt->addr + (y * txt->sl + x * (txt->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr_img + (y * mlx->sl + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

int	dir_wall(t_ray *ray)
{
	if (ray->side == 0 && ray->dirx < 0)
		return (2);
	else if (ray->side == 0 && ray->dirx > 0)
		return (0);
	else if (ray->side == 1 && ray->diry < 0)
		return (3);
	else
		return (1);
}

int	draw_wall(t_data *data, t_mlx *mlx, t_ray *ray, int y)
{
	int		wall_end;
	int		column;
	double	row;
	double	row_step;
	int		dirc;

	wall_end = (int)((WIN_H + ray->wall_len) / 2);
	dirc = dir_wall(ray);
	column = (int)((ray->hit_x + ray->hit_y) * data->txt[dirc].w)
		% data->txt[dirc].w;
	row = 0.00;
	row_step = (data->txt[dirc].h) / (double)ray->wall_len;
	while (ray->wall_h < wall_end)
	{
		if (ray->wall_h >= 0 && ray->wall_h < WIN_H)
			pixel_put(mlx, y, ray->wall_h,
				get_txt_color(&data->txt[dirc], column, (int)row));
		ray->wall_h++;
		row += row_step;
	}
	return (ray->wall_h);
}

void	draw_column(int x, t_ray *ray, t_data *data)
{
	int	y;

	y = -1;
	ray->wall_h = (int)((WIN_H - ray->wall_len) / 2);
	while (++y < ray->wall_h)
		pixel_put(data->mlx, x, y, data->ceilling);
	y = draw_wall(data, data->mlx, ray, x);
	while (y < WIN_H)
	{
		pixel_put(data->mlx, x, y, data->floor);
		y++;
	}
}
