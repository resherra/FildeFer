/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:34:46 by recherra          #+#    #+#             */
/*   Updated: 2025/02/21 17:51:41 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initial_values(t_bonus *init)
{
	init->degrees.x_degree = 60;
	init->degrees.z_degree = 0;
	init->degrees.y_degree = 0;
	init->degrees.axis = 'p';
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
	mlx_hook(mlx.window, 17, 0, close_btn, &mlx);
	mlx_hook(mlx.window, 2, 0, key_hook, &init);
	mlx_loop(mlx.connection);
}
