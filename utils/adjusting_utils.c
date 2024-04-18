/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjusting_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:50:23 by recherra          #+#    #+#             */
/*   Updated: 2024/04/17 18:50:25 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

void	scale(t_pcord *point1, t_pcord *point2, t_map_size *plan)
{
	point1->x *= plan->scale_f;
	point1->y *= plan->scale_f;
	point2->x *= plan->scale_f;
	point2->y *= plan->scale_f;
}

void	translate(t_pcord *point1, t_pcord *point2, t_map_size *plan)
{
    point1->x += plan->offset_x;
    point2->x += plan->offset_x;
	point1->y += plan->offset_y;
	point2->y += plan->offset_y;
}

void	factor(t_map_size *plan)
{
	int	width;

	plan->bounding_w = plan->max_x - plan->min_x;
	plan->bounding_h = plan->max_y - plan->min_y;
	width = 1100;
	if (width / plan->bounding_w < width / plan->bounding_h)
		plan->scale_f = width / plan->bounding_w;
	else
		plan->scale_f = width / plan->bounding_h;

	//scaling
	plan->min_x *= plan->scale_f;
	plan->min_y *= plan->scale_f;
    plan->max_x *= plan->scale_f;
    plan->max_y *= plan->scale_f;

    plan->offset_x = 0;
    plan->offset_y = 0;
    if (plan->min_x < 0)
        plan->offset_x += fabs(plan->min_x);
    if (plan->min_y < 0)
        plan->offset_y += fabs(plan->min_y);

    plan->offset_x += (WIDTH - plan->max_x - plan->offset_x) / 2;
    plan->offset_y += (HEIGHT - plan->max_y - plan->offset_y) / 2;
}
