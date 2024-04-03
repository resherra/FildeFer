/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:34:46 by recherra          #+#    #+#             */
/*   Updated: 2024/03/23 17:34:48 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <mlx.h>

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

void dda(float x1, float x2, float y1, float y2, void *mlx_window, void *mlx_connection, int color)
{
    x1 *= 10;
    y1 *= 10;
    x2 *= 10;
    y2 *= 10;
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
        mlx_pixel_put(mlx_connection, mlx_window, x1, y1, color);
        //	printf("x -> %.0f | y -> %.0f\n", x1, y1);
        x1 += xincre;
        y1 += yincre;
        i++;
    }
}

//main
int	main(int ac, char **av)
{
	t_pcord **points;
	t_map_size *plan;
	void *mlx;
	void *mlx_win;

//	printf("arg -> %s\n", av[1]);
	map_checker(ac, av[1]);
	plan = malloc(sizeof(t_map_size));
    plan->x = 0;
    plan->y = 0;
    points = map_parse(av[1], plan);
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1000, 500, "testing");

    int i = 0;
    while (i < plan->y)
    {
        int j = 0;
        while (j < plan->x)
        {
            if (j != plan->x - 1)
                dda(j, j + 1, i, i, mlx_win, mlx, points[i][j].color);
            if (i != plan->y - 1)
                dda(j, j, i, i + 1, mlx_win, mlx, points[i][j].color);
            j++;
        }
        i++;
    }

    mlx_loop(mlx);
    //free up memory
    for (int i = 0; i < plan->y; i++)
    {
        free(points[i]);
    }
    free(points);
    free(plan);
//	system("leaks -q a.out");
}