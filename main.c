/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:34:46 by recherra          #+#    #+#             */
/*   Updated: 2024/04/05 20:35:27 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	custom_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	events_manager(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(mlx->connection, mlx->window);
		exit(0);
	}
	return (0);
}

int close_btn(t_mlx *mlx)
{
    mlx_destroy_window(mlx->connection, mlx->window);
    exit(0);
}




void print_error(char *error_msg)
{
    ft_putstr(error_msg);
    exit(1);
}

int	main(int ac, char **av)
{
	t_pcord		**points;
	t_map_size	*plan;
	t_mlx		mlx;
	t_data		img;

	map_checker(ac, av[1]);
	plan = malloc(sizeof(t_map_size));
	if (!plan)
		return (0);
	points = map_parse(av[1], plan);
    if (!plan->y)
    {
        print_error("Fil de Fer: Empty file.\n");
    }
	projection(points, plan);
	factor(plan);
	mlx.connection = mlx_init();
	mlx.window = mlx_new_window(mlx.connection, WIDTH, HEIGHT, "Fil de fer");
	img.img = mlx_new_image(mlx.connection, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	draw(points, plan, &img);
	mlx_put_image_to_window(mlx.connection, mlx.window, img.img, 0, 0);
	mlx_key_hook(mlx.window, events_manager, &mlx);
    mlx_hook( mlx.window, 33, 1L<<17, close_btn, &mlx);
    mlx_loop(mlx.connection);
}
