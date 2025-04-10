/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:34:46 by recherra          #+#    #+#             */
/*   Updated: 2025/02/21 17:51:41 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int check_state(t_bonus *data)
{
    if (data->state.f || data->state.g || data->state.x || data->state.y || data->state.z || data->mouse_state.left_button || data->mouse_state.scroll_down || data->mouse_state.scroll_up)
        return (1);
    return (0);
}

int ultimate_hook(t_bonus *init)
{
    int check;

    check = 0;
    if (check_state(init))
        check = 1;
    if (init->state.f)
        init->calcs->scale_f += 0.25;
    if (init->state.g)
    {
        {
            if (init->calcs->scale_f - 1 < 0)
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

    if (init->mouse_state.scroll_down)
        init->calcs->scale_f += 1;
    if (init->mouse_state.scroll_up)
    {
        {
            if (init->calcs->scale_f - 2 < 0)
                return (0);
            init->calcs->scale_f -= 1;
        }
    }
    if (check == 1)
        re_render(init);
    init->mouse_state.scroll_up = 0;
    init->mouse_state.scroll_down = 0;
    return (0);
}
