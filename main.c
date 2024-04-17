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

#define WIDTH 1300
#define HEIGHT 1300

void	map_checker(int ac, char *map)
{
	if (ac != 2)
	{
		printf("more/less arguments");
		exit(1);
	}
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
	*(unsigned int *)dst = color;
}

void	get_res(float x, float y, t_map_size *plan)
{
	if (x > plan->max_x)
	{
		plan->max_x = x;
	}
	else if (x < plan->min_x)
	{
		plan->min_x = x;

	}
	if (y > plan->max_y)
	{
		plan->max_y = y;
	}
	else if (y < plan->min_y)
	{
		plan->min_y = y;
	}
}

void	projection(t_pcord ***points, t_map_size *plan)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	plan->max_x = (*points)[i][j].x;
	plan->min_x = (*points)[i][j].x;
	plan->max_y = (*points)[i][j].y;
	plan->min_y = (*points)[i][j].y;
	while (i < plan->y)
	{
		j = 0;
		while (j < plan->x)
		{
			rotate_z(&(*points)[i][j].x, &(*points)[i][j].y,
					&(*points)[i][j].z);
			rotate_x(&(*points)[i][j].x, &(*points)[i][j].y,
					&(*points)[i][j].z);
			get_res((*points)[i][j].x, (*points)[i][j].y, plan);
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->window, mlx->window);
		exit(0);
	}
	return (0);
}

void	dda(t_pcord point1, t_pcord point2, t_map_size *plan, t_data *img)
{
	int		steps;
	float	dx;
	float	dy;
	float	x_factor;
	float	y_factor;
	float	plus;
	int		i;


	//zoom
	plus = plan->scale_f;
	point1.x *= plus;
	point1.y *= plus;
	point2.x *= plus;
	point2.y *= plus;

    float offset = 0;
    float offset_y = 0;


	if (plan->min_x < 0)
	    offset += (0 - plan->min_x) * plus;
     if (plan->min_y < 0)
         offset_y += (0 - plan->min_y) * plus;


//	translation
	point1.x += offset;
	point2.x += offset;
	point1.y += offset_y;
	point2.y += offset_y;


	dx = point2.x - point1.x;
	dy = point2.y - point1.y;
	if (dx >= dy)
		steps = dx;
	else
		steps = dy;
	x_factor = dx / steps;
	y_factor = dy / steps;
	i = 0;
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


	projection(&points, plan);

    mlx.window = mlx_new_window(mlx.connection, WIDTH, HEIGHT, "testing");

    img.img = mlx_new_image(mlx.connection, WIDTH, HEIGHT);

    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	void f();

    printf("max x -> %f\n", plan->max_x);
    printf("min x -> %f\n", plan->min_x);
    printf("max y -> %f\n", plan->max_y);
    printf("min y -> %f\n", plan->min_y);


    plan->bounding_w = plan->max_x - plan->min_x;
    plan->bounding_h = plan->max_y - plan->min_y;


    //scale factor
    int width = 1100;


    if (width / plan->bounding_w < width / plan->bounding_h)
        plan->scale_f = width / plan->bounding_w;
    else
        plan->scale_f = width / plan->bounding_h;


    printf("scale f %f\n", plan->scale_f);


    plan->bounding_h = (plan->max_y - plan->min_y) * plan->scale_f;
    plan->bounding_h -= plan->bounding_h / 2;

    printf("new -> %f\n", plan->bounding_h);


    int i = 0;
	while (i < plan->y)
	{
		int j = 0;
		while (j < plan->x)
		{
			if (j != plan->x - 1)
			{
			    if (j == 0 && i == 0)
                {
			        printf("x-> %f | y -> %f\n", points[i][j].x, points[i][j].y);
                }
				dda(points[i][j], points[i][j + 1], plan, &img);
			}
			if (i != plan->y - 1)
			{
				dda(points[i][j], points[i + 1][j], plan, &img);
			}
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(mlx.connection, mlx.window, img.img, 0, 0);

	mlx_key_hook(mlx.window, key_hook, &mlx);

	mlx_loop(mlx.connection);

	for (int i = 0; i < plan->y; i++)
	{
		free(points[i]);
	}
	free(points);
	free(plan);
	system("leaks -q a.out");
}