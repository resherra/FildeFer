/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:07:12 by recherra          #+#    #+#             */
/*   Updated: 2024/04/17 20:07:13 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

void	end_free(t_pcord **points, t_map_size *plan)
{
	int	i;

	i = 0;
	while (i < plan->y)
	{
		free(points[i]);
		i++;
	}
	free(points);
	free(plan);
}
