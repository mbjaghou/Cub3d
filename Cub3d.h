/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbjaghou <mbjaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:59:08 by yachehbo          #+#    #+#             */
/*   Updated: 2022/11/10 13:02:45 by mbjaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "GNL/get_next_line.h"
# include <mlx.h>
# include <math.h>

# define WIN_H 1080
# define WIN_W 1080
# define SPEED 0.07
# define FOV 60

typedef struct s_txt
{
	void	*img;
	char	*addr;
	int		bpp;
	int		sl;
	int		en;
	int		w;
	int		h;
}	t_txt;

typedef struct s_ray
{
	double	p_dx;
	double	p_dy;
	double	dirx;
	double	diry;
	int		check_x;
	int		check_y;
	double	len_x;
	double	len_y;
	int		increm_x;
	int		increm_y;
	int		side;
	double	hit_x;
	double	hit_y;
	double	lenght;
	int		wall_h;
	int		wall_len;
}	t_ray;

typedef struct s_player
{
	int		x;
	int		y;
	double	dx;
	double	dy;
	double	dir;
	int		up;
	int		down;
	int		left;
	int		right;
	int		rot_left;
	int		rot_right;
}	t_player;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr_img;
	int		bpp;
	int		sl;
	int		en;
}	t_mlx;

typedef struct s_data
{
	t_mlx		*mlx;
	t_player	*player;
	t_ray		*ray;
	t_txt		*txt;
	char		**map;
	char		**scene;
	int			len;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor;
	int			ceilling;
}	t_data;

//SRCS
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	**ft_split(char *str, char *charset);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char *s1, char *set);

//parssing
int		parssing(int ac, char **av, t_data *data);
void	free_str(char **str);
//CHECKER
int		checker(int ac, char **av, t_data *data);
int		check_scene(t_data *data);
void	print_error(char *str);
int		check_color(char **colors);
//FILL
int		fill(t_data *data, int i, int j);
void	fill_scene(t_data *data, int f, int l);
int		fill_data(char *line, t_data *data);
int		fill_color(char **colors, t_data *data, char *str);
void	init_data(t_data *data);
char	**join_color(char **str);

void	free_data(t_data *data);

//INIT
int		init(t_data *data);
void	init_press(t_player *player);
//rcasting
int		create_image(t_data *data, t_mlx *mlx);
void	ray_cast(t_data *data, t_player *player);
//drawing
void	draw_column(int x, t_ray *ray, t_data *data);
///update
int		update(void *v_data);
void	update_player_pos(t_data *data);
//move
int		isWall(t_data *data, double x, double y);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
//hook
int		close_win(t_data *data);
int		handle_keypress(int key, t_data *data);
int		handle_keyrelease(int key, t_data *data);
#endif
