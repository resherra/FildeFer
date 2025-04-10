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
    data->state.f = 0;
    data->state.g = 0;
    data->state.x = 0;
    data->state.y = 0;
    data->state.z = 0;
    data->prev_x = 0;
    data->prev_y = 0;
}

void initialize_buttons_state(t_bonus *init)
{
    init->mouse_state.left_button = 0;
    init->mouse_state.scroll_up = 0;
    init->mouse_state.scroll_down = 0;
}

void initial_values(t_bonus *init)
{
    init->degrees.x_degree = 60;
    init->degrees.z_degree = 0;
    init->degrees.y_degree = 0;
    init->degrees.axis = 'p';
    initialize_keys_state(init);
    initialize_buttons_state(init);
}

void fill_init(t_bonus *init, t_map_size *plan, t_pcord **points, t_data img)
{
    init->calcs = plan;
    init->points = points;
    init->img = img;
}

void re_render(t_bonus *init)
{
    rebuild(init);
    draw(init->points, init->calcs, &init->img);
    mlx_put_image_to_window(init->mlx.connection, init->mlx.window,
                            init->img.img, 0, 0);
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
    mlx_hook(mlx.window, 04, 1L << 2, mouse_press, &init);   // button press
    mlx_hook(mlx.window, 05, 1L << 3, mouse_release, &init); // button release
    mlx_hook(mlx.window, 6, 1L << 6, mouse_hook, &init);
    mlx_loop_hook(mlx.connection, ultimate_hook, &init);
    mlx_hook(mlx.window, 17, 0, close_btn, &mlx);
    mlx_loop(mlx.connection);
}
