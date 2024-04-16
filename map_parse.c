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



t_pcord **map_parse(char *str, t_map_size *plan)
{
    t_pcord **points;

    cols_rows_count(str, plan);
    mem_allocation(plan, &points);
    map_dots(str, plan, &points);
    return points;
}
