/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:37:42 by recherra          #+#    #+#             */
/*   Updated: 2024/03/23 17:37:46 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# define WIDTH 1200
# define HEIGHT 1200

typedef struct s_map_size
{
	int			x;
	int			y;
	float		max_x;
	float		min_x;
	float		max_y;
	float		min_y;
	float		bounding_w;
	float		bounding_h;
	float		scale_f;
	float		offset_x;
	float		offset_y;
}				t_map_size;

typedef struct s_pcord
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_pcord;

typedef struct s_mlx
{
	void		*connection;
	void		*window;
}				t_mlx;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_dda
{
	float		steps;
	float		dx;
	float		dy;
	float		x_factor;
	float		y_factor;
}				t_dda;

typedef struct s_degree
{
	float		x_degree;
	float		y_degree;
	float		z_degree;
	char		axis;
}				t_degree;

typedef struct s_bonus
{
	t_mlx		mlx;
	t_map_size	*calcs;
	t_pcord		**points;
	t_data		img;
	t_degree	degrees;
}				t_bonus;

void			cols_rows_count(int fd, t_map_size *plan);
int				get_color(char *point);
void			map_dots(char *file, t_map_size *plan, t_pcord ***points);
void			mem_allocation(t_map_size *plan, t_pcord ***points);
t_pcord			**map_parse(char *str, t_map_size *plan);
void			map_checker(int ac, char *map);
int				ft_open(char *str);
void			projection(t_pcord **points, t_map_size *plan, t_degree degree);
void			translate(t_pcord *point1, t_pcord *point2, t_map_size *plan);
void			scale(t_pcord *point1, t_pcord *point2, t_map_size *plan);
void			draw(t_pcord **points, t_map_size *plan, t_data *img);
void			custom_mlx_pixel_put(t_data *data, int x, int y, int color);
void			factor(t_map_size *plan);
void			ft_putstr(char *s);

void			rotate_z(float *x, float *y, float *z, int degree);
void			rotate_x(float *x, float *y, float *z, int degree);
void			rotate_y(float *x, float *y, float *z, int degree);
void			rebuild(t_bonus *init);
void			reproject(int keycode, t_bonus *init);
int				readjust(int keycode, t_bonus *init);
int				key_hook(int keycode, t_bonus *init);
int				key_check(int key);
int				key_check(int key);
int				close_btn(t_mlx *mlx);
void			print_error(char *error_msg);

#endif