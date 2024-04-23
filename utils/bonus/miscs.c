/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:00:36 by recherra          #+#    #+#             */
/*   Updated: 2024/04/23 21:00:48 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"

int	key_check(int key)
{
	if (key == 53 || key == 35 || key == 123 || key == 124 || key == 125
		|| key == 126 || key == 3 || key == 5 || key == 7 || key == 6
		|| key == 16)
		return (1);
	return (0);
}

int	close_btn(t_mlx *mlx)
{
	mlx_destroy_window(mlx->connection, mlx->window);
	exit(0);
}

void	print_error(char *error_msg)
{
	ft_putstr(error_msg);
	exit(1);
}
