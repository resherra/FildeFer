/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:00:36 by recherra          #+#    #+#             */
/*   Updated: 2025/02/21 17:19:53 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int key_check(int key)
{
    if (key == ESC || key == FK || key == GK || key == XK || key == ZK || key == YK)
        return (1);
    return (0);
}

int close_btn(t_mlx *mlx)
{
    mlx_destroy_window(mlx->connection, mlx->window);
    exit(0);
}

void print_error(char *error_msg)
{
    ft_putstr(error_msg);
    exit(1);
}

void init_error(void *ptr)
{
    if (!ptr)
    {
        print_error("Unknown error happened!");
        exit(1);
    }
}

void mlx_initial(t_mlx *mlx, t_data *img)
{
    mlx->connection = mlx_init();
    init_error(mlx->connection);
    mlx->window = mlx_new_window(mlx->connection, WIDTH, HEIGHT, "Fil de fer");
    init_error(mlx->window);
    img->img = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
    init_error(img->img);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
                                  &img->line_length, &img->endian);
}
