/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:34:46 by recherra          #+#    #+#             */
/*   Updated: 2025/02/21 17:51:41 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void set_state(t_bonus *data, int key_button_code, int state)
{
    if (key_button_code == FK)
        data->state.f = state;
    if (key_button_code == GK)
        data->state.g = state;
    if (key_button_code == XK)
        data->state.x = state;
    if (key_button_code == ZK)
        data->state.z = state;
    if (key_button_code == YK)
        data->state.y = state;
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
