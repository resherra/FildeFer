/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:03:31 by recherra          #+#    #+#             */
/*   Updated: 2024/04/17 20:03:33 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

static void	dda(t_pcord point1, t_pcord point2, t_map_size *plan, t_data *img)
{
	int		i;
	t_dda	calcs;

	scale(&point1, &point2, plan);
	translate(&point1, &point2, plan);
	calcs.dx = point2.x - point1.x;
	calcs.dy = point2.y - point1.y;
	if (calcs.dx >= calcs.dy)
		calcs.steps = calcs.dx;
	else
		calcs.steps = calcs.dy;
	calcs.x_factor = calcs.dx / calcs.steps;
	calcs.y_factor = calcs.dy / calcs.steps;
	i = 0;
	while (i < calcs.steps)
	{
		custom_mlx_pixel_put(img, point1.x, point1.y, point1.color);
		point1.x += calcs.x_factor;
		point1.y += calcs.y_factor;
		i++;
	}
}

void	draw(t_pcord **points, t_map_size *plan, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < plan->y)
	{
		j = 0;
		while (j < plan->x)
		{
			if (j != plan->x - 1)
				dda(points[i][j], points[i][j + 1], plan, img);
			if (i != plan->y - 1)
				dda(points[i][j], points[i + 1][j], plan, img);
			j++;
		}
		i++;
	}
}