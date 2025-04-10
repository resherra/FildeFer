/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_hooking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 19:47:42 by recherra          #+#    #+#             */
/*   Updated: 2025/02/21 17:20:08 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void rebuild(t_bonus *init)
{
    mlx_destroy_image(init->mlx.connection, init->img.img);
    init->img.img = mlx_new_image(init->mlx.connection, WIDTH, HEIGHT);
    init_error(init->img.img);
    init->img.addr = mlx_get_data_addr(init->img.img, &init->img.bits_per_pixel,
                                       &init->img.line_length, &init->img.endian);
}
