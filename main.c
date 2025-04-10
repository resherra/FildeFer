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

void initialize_keys_state(t_bonus *data)
{
    data->state.left_arrow = 0;
    data->state.right_arrow = 0;
    data->state.up_arrow = 0;
    data->state.down_arrow = 0;
    data->state.f = 0;
    data->state.g = 0;
    data->state.x = 0;
    data->state.y = 0;
    data->state.z = 0;
    data->prev_x = 0;
    data->prev_y = 0;
}

void initial_values(t_bonus *init)
{
    init->degrees.x_degree = 60;
    init->degrees.z_degree = 0;
    init->degrees.y_degree = 0;
    init->degrees.axis = 'p';
    initialize_keys_state(init);
}

void fill_init(t_bonus *init, t_map_size *plan, t_pcord **points, t_data img)
{
    init->calcs = plan;
    init->points = points;
    init->img = img;
}

void set_state(t_bonus *data, int keycode, int state)
{
    if (keycode == FK)
        data->state.f = state;
    if (keycode == GK)
        data->state.g = state;
    if (keycode == XK)
        data->state.x = state;
    if (keycode == ZK)
        data->state.z = state;
    if (keycode == YK)
        data->state.y = state;
    if (keycode == PK)
        data->state.p = state;
    if (keycode == LA)
        data->state.left_arrow = state;
    if (keycode == RA)
        data->state.right_arrow = state;
    if (keycode == UA)
        data->state.up_arrow = state;
    if (keycode == DA)
        data->state.down_arrow = state;
}

int key_release(int keycode, t_bonus *data)
{
    set_state(data, keycode, 0);
    return (0);
}

int key_press(int keycode, t_bonus *data)
{
    if (keycode == ESC)
    {
        mlx_destroy_window(data->mlx.connection, data->mlx.window);
        exit(0);
    }
    if (key_check(keycode) == 0)
        return (0);
    set_state(data, keycode, 1);
    return (0);
}

int check_state(t_bonus *data)
{
    if (data->state.right_arrow ||
        data->state.left_arrow ||
        data->state.up_arrow ||
        data->state.down_arrow || data->state.f || data->state.g || data->state.x || data->state.y || data->state.z)
        return (1);
    return (0);
}

void re_render(t_bonus *init)
{
    rebuild(init);
    draw(init->points, init->calcs, &init->img);
    mlx_put_image_to_window(init->mlx.connection, init->mlx.window,
                            init->img.img, 0, 0);
}

int ultimate_hook(t_bonus *init)
{
    int check;

    check = 0;
    if (check_state(init))
        check = 1;
    if (init->state.right_arrow)
        init->calcs->offset_x += 2;
    if (init->state.left_arrow)
        init->calcs->offset_x -= 2;
    if (init->state.up_arrow)
        init->calcs->offset_y -= 2;
    if (init->state.down_arrow)
        init->calcs->offset_y += 2;
    if (init->state.f)
        init->calcs->scale_f += 0.25;
    if (init->state.g)
    {
        {
            if (init->calcs->scale_f - 4 < 0)
                return (0);
            init->calcs->scale_f -= 0.25;
        }
    }
    if (init->state.x)
    {
        init->degrees.x_degree = 1;
        init->degrees.axis = 'x';
        projection(init->points, init->calcs, init->degrees);
    }
    if (init->state.y)
    {
        init->degrees.y_degree = 1;
        init->degrees.axis = 'y';
        projection(init->points, init->calcs, init->degrees);
    }
    if (init->state.z)
    {
        init->degrees.z_degree = 1;
        init->degrees.axis = 'z';
        projection(init->points, init->calcs, init->degrees);
    }
    if (check == 1)
        re_render(init);
    return (0);
}

int mouse_hook(int x, int y, t_bonus *data)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        if (x < data->prev_x)
        {
            data->degrees.y_degree = -2;
            data->degrees.axis = 'y';
            projection(data->points, data->calcs, data->degrees);
        }
        else if (x > data->prev_x)
        {
            data->degrees.y_degree = 2;
            data->degrees.axis = 'y';
            projection(data->points, data->calcs, data->degrees);
        }
        if (y < data->prev_y)
        {
            data->degrees.x_degree = 2;
            data->degrees.axis = 'x';
            projection(data->points, data->calcs, data->degrees);
        }
        else if (y > data->prev_y)
        {
            data->degrees.x_degree = -2;
            data->degrees.axis = 'x';
            projection(data->points, data->calcs, data->degrees);
        }
        data->prev_x = x;
        data->prev_y = y;
        re_render(data);
    }
    return (0);
}

int main(int ac, char **av)
{
    t_pcord **points;
    t_map_size *plan;
    t_mlx mlx;
    t_data img;
    t_bonus init;

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
    mlx_hook(mlx.window, 2, 1L << 0, key_press, &init);
    mlx_hook(mlx.window, 3, 1L << 1, key_release, &init);
    mlx_hook(mlx.window, 6, 1L << 6, mouse_hook, &init);
    mlx_loop_hook(mlx.connection, ultimate_hook, &init);
    mlx_hook(mlx.window, 17, 0, close_btn, &mlx);
    mlx_loop(mlx.connection);
}
