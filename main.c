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

#define HEIGHT 1800
#define WIDTH 1800

//int mouse_hook(int keycode, t_mlx *mlx)
//{
//    (void)mlx;
//    if (keycode == 5)
//    {
//            write(1, "scroll down\n", 11);
//    }
//    return (0);
//
//}

void	map_checker(int ac, char *map)
{
	//check the number of args
	if (ac != 2)
	{
		printf("more/less arguments");
		exit(1);
	}
	//args validation
	if (ft_strlen(map) <= 4 || !ft_strnstr(map, ".fdf", ft_strlen(map)))
	{
		printf("invalid file");
		exit(1);
	}
}



void	custom_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void projection()
{

}

void dda_basic(int x, int y, float x1, float x2, float y1, float y2, int color, int z1, int z2, t_data *img)
{
    //zoom


    float scale_factor_x = WIDTH / x;
    float scale_factor_y = HEIGHT / y;


    float plus_x = 2;
    float plus_y = 2;
    x1 *= plus;
    y1 *= plus;
    x2 *= plus;
    y2 *= plus;
    z1 *= plus;
    z2 *= plus;


    float scale_factor_x = WIDTH / x;
    float scale_factor_y = HEIGHT / y;

    printf("x -> %d\n", x);
    printf("y -> %d\n", y);

    //projection
    t_vector point1;
    t_vector point2;
    t_vector rotated_z;
    t_vector rotated_z2;
    t_vector rotated_x;
    t_vector rotated_x2;


    point1.x = x1;
    point1.y = y1;
    point1.z = z1;


    point2.x = x2;
    point2.y = y2;
    point2.z = z2;

    rotated_z = rotate_z(point1);
    rotated_z2 = rotate_z(point2);

    rotated_x = rotate_x(rotated_z);
    rotated_x2 = rotate_x(rotated_z2);



    //translation
    rotated_x.x += WIDTH / 2;
    rotated_x2.x += WIDTH / 2;

    rotated_x.y +=  400;
    rotated_x2.y +=  400;


    //drawing
    int steps;
    float dx;
    float dy;
    float xincre;
    float yincre;

    dx = rotated_x2.x - rotated_x.x;
    dy = rotated_x2.y  - rotated_x.y;
    if (dx >= dy)
        steps = dx;
    else
        steps = dy;
    xincre = dx / steps;
    yincre = dy / steps;

    int i = 0;
    while (i < steps)
    {
        custom_mlx_pixel_put(img, rotated_x.x, rotated_x.y, color);
        rotated_x.x += xincre;
        rotated_x.y += yincre;
        i++;
    }
}


int	key_hook(int keycode, t_mlx *mlx)
{
    if(keycode == 53)
    {
        mlx_destroy_window(mlx->window, mlx->window);
        exit(0);
    }
    return (0);
}

//main
int	main(int ac, char **av)
{
	t_pcord **points;
	t_map_size *plan;
	t_mlx mlx;
    t_data img;

	map_checker(ac, av[1]);
	plan = malloc(sizeof(t_map_size));
    plan->x = 0;
    plan->y = 0;
    points = map_parse(av[1], plan);
    mlx.connection = mlx_init();
    mlx.window = mlx_new_window(mlx.connection, WIDTH, HEIGHT, "testing");


    img.img = mlx_new_image(mlx.connection, HEIGHT, WIDTH);

    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
            &img.endian);

    int i = 0;
    while (i < plan->y)
    {
        int j = 0;
        while (j < plan->x)
        {
            if (j != plan->x - 1)
                dda_basic(plan->x, plan->y, j, j + 1, i, i, points[i][j].color, points[i][j].z, points[i][j+1].z, &img);
            if (i != plan->y - 1)
                dda_basic(plan->x, plan->y, j, j, i, i + 1, points[i][j].color,  points[i][j].z, points[i + 1][j].z, &img);
            j++;
        }
        i++;
    }


    mlx_put_image_to_window(mlx.connection, mlx.window, img.img, 0, 0);

    mlx_key_hook(mlx.window, key_hook, &mlx);
//    mlx_mouse_hook(mlx.window, mouse_hook, &mlx);


    mlx_loop(mlx.connection);
//    free up memory
    for (int i = 0; i < plan->y; i++)
    {
        free(points[i]);
    }
    free(points);
    free(plan);
	system("leaks -q a.out");
}