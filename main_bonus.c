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

#include "fdf_bonus.h"

void	initial_values(t_bonus *init)
{
	init->degrees.z_degree = 45;
	init->degrees.x_degree = 53.264;
	init->degrees.y_degree = 0;
	init->degrees.axis = 'i';
}

void	mlx_initial(t_mlx *mlx, t_data *img)
{
	mlx->connection = mlx_init();
	mlx->window = mlx_new_window(mlx->connection, WIDTH, HEIGHT, "Fil de fer");
	img->img = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	fill_init(t_bonus *init, t_map_size *plan, t_pcord **points, t_data img)
{
	init->calcs = plan;
	init->points = points;
	init->img = img;
}

int	main(int ac, char **av)
{
	t_pcord		**points;
	t_map_size	*plan;
	t_mlx		mlx;
	t_data		img;
	t_bonus		init;

	map_checker(ac, av[1]);
	plan = malloc(sizeof(t_map_size));
	if (!plan)
		return (0);
	points = map_parse(av[1], plan);
	init.cpy = duplicate_arr(plan, points);
	if (!plan->y)
		print_error("Fil de Fer: Empty file.\n");
	initial_values(&init);
	projection(points, plan, init.degrees);
	factor(plan);
	mlx_initial(&mlx, &img);
	init.mlx = mlx;
	fill_init(&init, plan, points, img);
	draw(points, plan, &img);
	mlx_put_image_to_window(mlx.connection, mlx.window, img.img, 0, 0);
	mlx_key_hook(mlx.window, key_hook, &init);
	mlx_hook(mlx.window, 17, 0, close_btn, &mlx);
	mlx_loop(mlx.connection);
}
