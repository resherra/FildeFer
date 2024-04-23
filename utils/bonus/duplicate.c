/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:58:39 by recherra          #+#    #+#             */
/*   Updated: 2024/04/23 20:58:41 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf_bonus.h"

t_pcord	**duplicate_arr(t_map_size *plan, t_pcord **points)
{
	int		i;
	int		j;
	t_pcord	**cpy;

	i = 0;
	j = 0;
	mem_allocation(plan, &cpy);
	while (i < plan->y)
	{
		j = 0;
		while (j < plan->x)
		{
			cpy[i][j].x = points[i][j].x;
			cpy[i][j].y = points[i][j].y;
			cpy[i][j].z = points[i][j].z;
			cpy[i][j].color = points[i][j].color;
			j++;
		}
		i++;
	}
	return (cpy);
}
