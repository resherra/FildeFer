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

#define HEIGHT 1000
#define WIDTH 1000

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


void translation()
{

}



//void dda_basic(float x1, float x2, float y1, float y2, int color, int z1, int z2, t_data *img)
//{
//    float plus = 10;
//    x1 *= plus;
//    y1 *= plus;
//    x2 *= plus;
//    y2 *= plus;
//    z1 *= plus;
//    z2 *= plus;
//
//    //projection
//
//
//
//    //translation
//    rotated_x.x += WIDTH / 2;
//    rotated_x2.x += WIDTH / 2;
//
//    rotated_x.y +=  400;
//    rotated_x2.y +=  400;
//
//
//    //drawing
//    int steps;
//    float dx;
//    float dy;
//    float xincre;
//    float yincre;
//
//    dx = rotated_x2.x - rotated_x.x;
//    dy = rotated_x2.y  - rotated_x.y;
//    if (dx >= dy)
//        steps = dx;
//    else
//        steps = dy;
//    xincre = dx / steps;
//    yincre = dy / steps;
//
//    int i = 0;
//    while (i < steps)
//    {
//        custom_mlx_pixel_put(img, rotated_x.x, rotated_x.y, color);
//        rotated_x.x += xincre;
//        rotated_x.y += yincre;
//        i++;
//    }
//}


void projection(t_pcord ***points, t_map_size *plan)
{
    int i = 0;

    printf("x -> %d\n", plan->x);
    printf("y -> %d\n", plan->y);




    while (i < plan->y)
    {
        int j = 0;
        while (j < plan->x)
        {
            rotate_z(&(*points)[i][j].x, &(*points)[i][j].y, &(*points)[i][j].z);
            rotate_x(&(*points)[i][j].x, &(*points)[i][j].y, &(*points)[i][j].z);
            j++;
        }
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




void dda(t_pcord point1, t_pcord point2, t_data *img)
{
    int steps;
    float dx;
    float dy;
    float x_factor;
    float y_factor;

    int plus = 10;
    point1.x *= plus;
    point1.y *= plus;
    point1.z *= plus;
    point2.x *= plus;
    point2.y *= plus;
    point2.z *= plus;

    dx = point2.x - point1.x;
    dy = point2.y - point1.y;

    if (dx >= dy)
        steps = dx;
    else
        steps = dy;

    x_factor = dx / steps;
    y_factor = dy / steps;

    int i = 0;
    while (i < steps)
    {
        custom_mlx_pixel_put(img, point1.x, point1.y, point1.color);
        point1.x += x_factor;
        point1.y += y_factor;
        i++;
    }

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


    projection(&points, plan);

    int i = 0;
    while (i < plan->y)
    {
        int j = 0;
        while (j < plan->x)
        {
            if (j != plan->x - 1)
            {
                dda(points[i][j], points[i][j + 1], &img);
            }
            if (i != plan->y - 1)
            {
                dda(points[i][j], points[i + 1][j], &img);
            }
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