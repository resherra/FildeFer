/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:34:46 by recherra          #+#    #+#             */
/*   Updated: 2025/02/21 17:51:41 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void rotate_hooks_y(t_bonus *data, int sign)
{
    data->degrees.y_degree = 2 * sign;
    data->degrees.axis = 'y';
    projection(data->points, data->calcs, data->degrees);
}

static void rotate_hooks_x(t_bonus *data, int sign)
{
    data->degrees.x_degree = 2 * sign;
    data->degrees.axis = 'x';
    projection(data->points, data->calcs, data->degrees);
}

int mouse_hook(int x, int y, t_bonus *data)
{
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        if (data->mouse_state.left_button && (x != data->prev_x || y != data->prev_y))
        {
            if (x < data->prev_x)
                data->calcs->offset_x += 15;
            if (x > data->prev_x)
                data->calcs->offset_x -= 15;
            if (y < data->prev_y)
                data->calcs->offset_y += 15;
            if (y > data->prev_y)
                data->calcs->offset_y -= 15;
        }
        else
        {
            if (x < data->prev_x)
                rotate_hooks_y(data, -1);
            else if (x > data->prev_x)
                rotate_hooks_y(data, 1);
            if (y < data->prev_y)
                rotate_hooks_x(data, 1);
            else if (y > data->prev_y)
                rotate_hooks_x(data, -1);
        }
        data->prev_x = x;
        data->prev_y = y;
        re_render(data);
    }
    return (0);
}

static int button_check(int button)
{
    if (button == 1 || button == 4 || button == 5)
        return 1;
    return 0;
}

static void set_button_state(t_bonus *data, int button_code, int state)
{
    if (button_code == 1)
        data->mouse_state.left_button = state;
    if (button_code == 4)
    {
        data->mouse_state.scroll_down = !state;
        data->mouse_state.scroll_up = state;
    }
    if (button_code == 5)
    {
        data->mouse_state.scroll_down = state;
        data->mouse_state.scroll_up = !state;
    }
}

int mouse_release(int button, int x, int y, t_bonus *data)
{
    set_button_state(data, button, 0);
    return (0);
}

int mouse_press(int button, int x, int y, t_bonus *data)
{
    if (button_check(button) == 0)
        return 0;
    set_button_state(data, button, 1);
    return (0);
}
