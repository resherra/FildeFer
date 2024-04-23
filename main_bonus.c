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

#include "init_bonus.h"

void	custom_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


void rebuild(t_bonus *testing)
{
    mlx_destroy_image(testing->mlx.connection, testing->img.img);
    testing->img.img = mlx_new_image(testing->mlx.connection, WIDTH, HEIGHT);
    testing->img.addr = mlx_get_data_addr(testing->img.img, &testing->img.bits_per_pixel, &testing->img.line_length,
                                          &testing->img.endian);
}

//linux
int	key_hook(int keycode, t_bonus *testing)
{
    rebuild(testing);
	if (keycode == XK_Escape)
	{
        mlx_destroy_window(testing->mlx.connection, testing->mlx.window);
        exit(0);
	}
    if (keycode == XK_Right)
        testing->calcs->offset_x += 20;
    if (keycode == XK_Left)
        testing->calcs->offset_x -= 20;
    if (keycode == XK_Up)
        testing->calcs->offset_y -= 20;
    if (keycode == XK_Down)
        testing->calcs->offset_y += 20;
    if (keycode == 102) //f
       testing->calcs->scale_f += 1.5;
    if (keycode == 103) //g
    {
        if (testing->calcs->scale_f - 1.5 < 0)
            return 0;
        testing->calcs->scale_f -= 1.5;
    }
    if (keycode == 120) //x
    {
//        rebuild(testing);
        testing->degrees.x_degree = 10.00;
        testing->degrees.axis = 'x';
        projection(testing->points, testing->calcs, testing->degrees);
        static float degreex;

        degreex += testing->degrees.x_degree;
    }
    if (keycode == 122) //z
    {
//        rebuild(testing);
        testing->degrees.z_degree = 10.00;
        testing->degrees.axis = 'z';
        projection(testing->points, testing->calcs, testing->degrees);
        static float degreez;

        degreez += testing->degrees.z_degree;
    }
    if (keycode == 121) //y
    {
//        rebuild(testing);
        testing->degrees.y_degree = 10.00;
        testing->degrees.axis = 'y';
        projection(testing->points, testing->calcs, testing->degrees);

        static float degreey;

        degreey += testing->degrees.y_degree;
    }
    draw(testing->points, testing->calcs, &testing->img);
    mlx_put_image_to_window(testing->mlx.connection, testing->mlx.window, testing->img.img, 0, 0);
    return (0);
}

int close_btn(t_mlx *mlx)
{
    mlx_destroy_window(mlx->connection, mlx->window);
    exit(0);
}

//macos
//int	key_hook(int keycode, t_mlx *mlx)
//{
//	if (keycode == 53)
//	{
//		mlx_destroy_window(mlx->connection, mlx->window);
//		exit(0);
//	}
//    return 0;
//}

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
    t_bonus testing;
    t_degree rotation_degree;



	map_checker(ac, av[1]);
	plan = malloc(sizeof(t_map_size));
	if (!plan)
		return (0);
	points = map_parse(av[1], plan);
    if (!plan->y)
    {
        print_error("Fil de Fer: Empty file.\n");
    }
//    rotation_degree.z_degree = 45;
//    rotation_degree.x_degree = 35.264;
    rotation_degree.z_degree = 45;
    rotation_degree.x_degree = 30;
    rotation_degree.y_degree = 30;
    rotation_degree.axis = 'i';
	projection(points, plan, rotation_degree);
	factor(plan);
	mlx.connection = mlx_init();
	mlx.window = mlx_new_window(mlx.connection, WIDTH, HEIGHT, "Fil de fer");
	img.img = mlx_new_image(mlx.connection, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    //init
    testing.mlx = mlx;
    testing.calcs = plan;
    testing.points = points;
    testing.img = img;
    testing.degrees = rotation_degree;
    //draw

    draw(points, plan, &img);
	mlx_put_image_to_window(mlx.connection, mlx.window, img.img, 0, 0);
	mlx_key_hook(mlx.window, key_hook, &testing);
    mlx_hook( mlx.window, 33, 1L<<17, close_btn, &mlx);
    mlx_loop(mlx.connection);
}
