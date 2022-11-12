/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcasting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:20:13 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/12 10:56:28 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	init_ray(t_data *data, t_ray *ray, double ray_angle)
{
	ray->p_dx = data->player->dx;
	ray->p_dy = data->player->dy;
	ray->check_x = (int)data->player->dx;
	ray->check_y = (int)data->player->dy;
	ray->dirx = cos(ray_angle);
	ray->diry = sin(ray_angle);
	ray->side = 0;
	ray->increm_x = 0;
	ray->increm_y = 0;
}

void	f_intersection(t_ray *ray, t_data *data, double ray_angle)
{
	init_ray(data, data->ray, ray_angle);
	if (ray->dirx < 0)
	{
		ray->increm_x = -1;
		ray->len_x = (ray->p_dx - ((double)ray->check_x)) / fabs(ray->dirx);
	}
	else
	{
		ray->increm_x = 1;
		ray->len_x = ((double)(ray->check_x + 1) - ray->p_dx) / fabs(ray->dirx);
	}
	if (ray->diry < 0)
	{
		ray->increm_y = -1;
		ray->len_y = (ray->p_dy - ((double)ray->check_y)) / fabs(ray->diry);
	}
	else
	{
		ray->increm_y = 1;
		ray->len_y = ((double)(ray->check_y + 1) - ray->p_dy) / fabs(ray->diry);
	}
}

void	dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->len_x < ray->len_y)
		{
			ray->check_x += ray->increm_x;
			ray->lenght = ray->len_x;
			ray->len_x += (1 / fabs(ray->dirx));
			ray->side = 0;
		}
		else
		{
			ray->check_y += ray->increm_y;
			ray->lenght = ray->len_y;
			ray->len_y += (1 / fabs(ray->diry));
			ray->side = 1;
		}
		if (data->scene[ray->check_y][ray->check_x] == '1')
			hit = 1;
	}
	ray->hit_x = ray->p_dx + ray->dirx * ray->lenght;
	ray->hit_y = ray->p_dy + ray->diry * ray->lenght;
}

void	ray_cast(t_data *data, t_player *player)
{
	int 	x;
	double	ray_angle;
	double	camera_angle;
	double	angle_inc;

	x = 0;
	angle_inc = (double)FOV / (double)WIN_W;
	while (x < WIN_W)
	{
		ray_angle = player->dir + ((-FOV / 2)
				+ (double)x * angle_inc) * (M_PI / 180);
		camera_angle = ((-FOV / 2) + (double)x * angle_inc) * (M_PI / 180);
		f_intersection(data->ray, data, ray_angle);
		dda(data, data->ray);
		data->ray->wall_len = WIN_H / (data->ray->lenght * cos(camera_angle));
		draw_column(x, data->ray, data);
		x++;
	}
}

int	create_image(t_data *data, t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->ptr, WIN_W, WIN_H);
	if (!mlx->img)
		return (1);
	mlx->addr_img = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->en);
	ray_cast(data, data->player);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return (0);
}
