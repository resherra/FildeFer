/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_hooking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:47:42 by recherra          #+#    #+#             */
/*   Updated: 2024/04/26 16:48:35 by recherra         ###   ########.fr       */
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

void	reproject(int keycode, t_bonus *init)
{
	if (keycode == 7)
	{
		init->degrees.x_degree = 5;
		init->degrees.axis = 'x';
		projection(init->points, init->calcs, init->degrees);
	}
	else if (keycode == 16)
	{
		init->degrees.y_degree = 5;
		init->degrees.axis = 'y';
		projection(init->points, init->calcs, init->degrees);
	}
	else if (keycode == 6)
	{
		init->degrees.z_degree = 5;
		init->degrees.axis = 'z';
		projection(init->points, init->calcs, init->degrees);
	}
}

int	readjust(int keycode, t_bonus *init)
{
	if (keycode == 124)
		init->calcs->offset_x += 20;
	else if (keycode == 123)
		init->calcs->offset_x -= 20;
	else if (keycode == 126)
		init->calcs->offset_y -= 20;
	else if (keycode == 125)
		init->calcs->offset_y += 20;
	else if (keycode == 3)
		init->calcs->scale_f += 1;
	else if (keycode == 5)
	{
		if (init->calcs->scale_f - 1 < 0)
			return (0);
		init->calcs->scale_f -= 1;
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
	draw(init->points, init->calcs, &init->img);
	mlx_put_image_to_window(init->mlx.connection, init->mlx.window,
		init->img.img, 0, 0);
	return (0);
}
