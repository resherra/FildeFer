/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_hooking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:47:42 by recherra          #+#    #+#             */
/*   Updated: 2024/04/23 21:38:36 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"

void	rebuild(t_bonus *init)
{
	mlx_destroy_image(init->mlx.connection, init->img.img);
	init->img.img = mlx_new_image(init->mlx.connection, WIDTH, HEIGHT);
	init->img.addr = mlx_get_data_addr(init->img.img, &init->img.bits_per_pixel,
			&init->img.line_length, &init->img.endian);
}

void	reproject_basic(int keycode, t_bonus *init)
{
	if (keycode == 7)
	{
		init->degrees.x_degree = 10.00;
		init->degrees.axis = 'x';
		projection(init->points, init->calcs, init->degrees);
	}
	if (keycode == 16)
	{
		init->degrees.y_degree = 10.00;
		init->degrees.axis = 'y';
		projection(init->points, init->calcs, init->degrees);
	}
	if (keycode == 6)
	{
		init->degrees.z_degree = 10.00;
		init->degrees.axis = 'z';
		projection(init->points, init->calcs, init->degrees);
	}
}

void	reproject(int keycode, t_bonus *init)
{
	reproject_basic(keycode, init);
	if (keycode == 35)
	{
		init->degrees.x_degree = 90;
		init->degrees.z_degree = 0;
		init->degrees.y_degree = 0;
		init->degrees.axis = 'p';
		projection(init->cpy, init->calcs, init->degrees);
	}
}

int	readjust(int keycode, t_bonus *init)
{
	if (keycode == 124)
		init->calcs->offset_x += 20;
	if (keycode == 123)
		init->calcs->offset_x -= 20;
	if (keycode == 126)
		init->calcs->offset_y -= 20;
	if (keycode == 125)
		init->calcs->offset_y += 20;
	if (keycode == 3)
		init->calcs->scale_f += 1.4;
	if (keycode == 5)
	{
		if (init->calcs->scale_f - 1.4 < 0)
			return (0);
		init->calcs->scale_f -= 1.4;
	}
	return (1);
}

int	key_hook(int keycode, t_bonus *init)
{
	if (key_check(keycode))
		rebuild(init);
	if (keycode == 53)
	{
		mlx_destroy_window(init->mlx.connection, init->mlx.window);
		exit(0);
	}
	readjust(keycode, init);
	reproject(keycode, init);
	if (keycode == 35)
		draw(init->cpy, init->calcs, &init->img);
	else if (key_check(keycode))
		draw(init->points, init->calcs, &init->img);
	mlx_put_image_to_window(init->mlx.connection, init->mlx.window,
		init->img.img, 0, 0);
	return (0);
}
