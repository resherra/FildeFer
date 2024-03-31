/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:32:40 by recherra          #+#    #+#             */
/*   Updated: 2024/03/31 22:55:51 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	print(t_pcord **points, t_map_size *plan)
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
            printf("%3d", points[i][j].z);
            j++;
        }
        printf("\n");
        i++;
    }
}

t_pcord **map_parse(char *str, t_map_size *plan)
{
    t_pcord **points;

    cols_rows_count(str, plan);
    mem_allocation(plan, &points);
    map_dots(str, plan, &points);
    print(points, plan);
    return points;
}
