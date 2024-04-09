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

//rotation around z
t_vector rotate_z(t_vector v) {
    double cos_theta = cos(M_PI_4);
    double sin_theta = sin(M_PI_4);

    t_vector new_v;
    new_v.x = cos_theta * v.x - sin_theta * v.y;
    new_v.y = sin_theta * v.x + cos_theta * v.y;
    new_v.z = v.z;

    return new_v;
}

//rotation around x
t_vector rotate_x(t_vector v) {
    double cos_theta = cos(atan(sqrt(2)));
    double sin_theta = sin(atan(sqrt(2)));

    t_vector new_v;
    new_v.x = v.x;
    new_v.y = cos_theta * v.y - sin_theta * v.z ;
    new_v.z = sin_theta * v.y  + cos_theta * v.z;

    return new_v;
}


void dda(float x1, float x2, float y1, float y2, t_mlx *mlx, int color, int z1, int z2)
{
    int plus = 20;
    x1 *= plus;
    y1 *= plus;
    x2 *= plus;
    y2 *= plus;
    z1 *= plus;
    z2 *= plus;

    t_vector point1;
    t_vector point2;

    point1.x = x1;
    point1.y = y1;
    point1.z = z1;


    point2.x = x2;
    point2.y = y2;
    point2.z = z2;

    t_vector rotated_z = rotate_z(point1);
    t_vector rotated_z2 = rotate_z(point2);

    t_vector rotated_x = rotate_x(rotated_z);
    t_vector rotated_x2 = rotate_x(rotated_z2);

    rotated_x.x += WIDTH / 2;
    rotated_x2.x += WIDTH / 2;

    rotated_x.y +=  200;
    rotated_x2.y +=  200;


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
        mlx_pixel_put((*mlx).mlx_connection, (*mlx).mlx_window, rotated_x.x, rotated_x.y, color);

        rotated_x.x += xincre;
        rotated_x.y += yincre;
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