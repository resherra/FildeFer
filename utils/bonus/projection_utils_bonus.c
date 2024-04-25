/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:59:39 by recherra          #+#    #+#             */
/*   Updated: 2024/04/25 17:25:14 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"

static void	get_res(float x, float y, t_map_size *plan)
{
	if (x > plan->max_x)
		plan->max_x = x;
	else if (x < plan->min_x)
		plan->min_x = x;
	if (y > plan->max_y)
		plan->max_y = y;
	else if (y < plan->min_y)
		plan->min_y = y;
}

static void	rotation(t_pcord **points, t_degree rotation_degree, int i, int j)
{
	if (rotation_degree.axis == 'z')
		rotate_z(&points[i][j].x, &points[i][j].y, &points[i][j].z,
			rotation_degree.z_degree);
	if (rotation_degree.axis == 'y')
		rotate_y(&points[i][j].x, &points[i][j].y, &points[i][j].z,
			rotation_degree.y_degree);
	if (rotation_degree.axis == 'x' || rotation_degree.axis == 'p')
		rotate_x(&points[i][j].x, &points[i][j].y, &points[i][j].z,
			rotation_degree.x_degree);
}

void	projection(t_pcord **points, t_map_size *plan, t_degree rotation_degree)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	plan->max_x = points[i][j].x;
	plan->min_x = points[i][j].x;
	plan->max_y = points[i][j].y;
	plan->min_y = points[i][j].y;
	while (i < plan->y)
	{
		j = 0;
		while (j < plan->x)
		{
			rotation(points, rotation_degree, i, j);
			get_res(points[i][j].x, points[i][j].y, plan);
			j++;
		}
		i++;
	}
}
