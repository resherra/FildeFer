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
#include <math.h>
#include <mlx.h>

#define HEIGHT 1800
#define WIDTH 1800

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

//void  isometric(int x, int y, int z)
//{
//    int tmp;
//

//
//    printf("y -> %d\n", y);
//    printf("x -> %d\n", x);
//
//}

void dda(float x1, float x2, float y1, float y2, t_mlx *mlx, int color, int z, int z1)
{
    int plus = 20;
    x1 *= plus;
    y1 *= plus;
    x2 *= plus;
    y2 *= plus;
    z *= plus;
    z1 *= plus;


    // int temp_x1 = x1;
    // int temp_y1 = y1;

    // x1 = (temp_x1 - y1) * cos(0.5);
    // y1 = (temp_x1 + temp_y1) * sin(0.5) - z;

    // int temp_x2 = x2;
    // int temp_y2 = y2;

    // x2 = (temp_x2 - y2) * cos(0.4);
    // y2 = (temp_x2 + temp_y2) * sin(0.4) - z1;


// 0.523599
    int  tmp = x1;
    x1 = (tmp - y1) * cos(0.7071);
    y1 = (tmp + y1) * sin(0.7071) - z;

    int  tmp2 = x2;
    x2 = (tmp2 - y2) * cos(0.7071);
    y2 = (tmp2 + y2) * sin(0.7071) - z1;


    (void)z;
    (void)z1;

    x1 += WIDTH / 2;
    x2 += WIDTH / 2;

    y1 +=  200;
    y2 +=  200;


    int steps;
    float dx;
    float dy;
    float xincre;
    float yincre;

    dx = x2 - x1;
    dy = y2 - y1;
    if (dx >= dy)
        steps = dx;
    else
        steps = dy;
    xincre = dx / steps;
    yincre = dy / steps;

    int i = 0;
    while (i < steps)
    {
        mlx_pixel_put((*mlx).mlx_connection, (*mlx).mlx_window, x1, y1, color);
        x1 += xincre;
        y1 += yincre;
        i++;
    }
//    mlx_pixel_put((*mlx).mlx_connection, (*mlx).mlx_window, x1, y1, color);

}

//main
int	main(int ac, char **av)
{
	t_pcord **points;
	t_map_size *plan;
	t_mlx mlx;

	map_checker(ac, av[1]);
	plan = malloc(sizeof(t_map_size));
    plan->x = 0;
    plan->y = 0;
    points = map_parse(av[1], plan);
    mlx.mlx_connection = mlx_init();
    mlx.mlx_window = mlx_new_window(mlx.mlx_connection, WIDTH, HEIGHT, "testing");

    int i = 0;
    while (i < plan->y)
    {
        int j = 0;
        while (j < plan->x)
        {
//            isometric(j, i, );
            if (j != plan->x - 1)
                dda(j, j + 1, i, i, &mlx, points[i][j].color, points[i][j].z, points[i][j+1].z);
            if (i != plan->y - 1)
                dda(j, j, i, i + 1, &mlx, points[i][j].color,  points[i][j].z, points[i + 1][j].z);
            j++;
        }
        i++;
    }

    mlx_loop(mlx.mlx_connection);
    //free up memory
    for (int i = 0; i < plan->y; i++)
    {
        free(points[i]);
    }
    free(points);
    free(plan);
//	system("leaks -q a.out");
}