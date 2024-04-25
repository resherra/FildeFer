/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:32:40 by recherra          #+#    #+#             */
/*   Updated: 2024/04/25 19:35:34 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	ft_open(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror("Fil de Fer");
		exit(1);
	}
	return (fd);
}

t_pcord	**map_parse(char *str, t_map_size *plan)
{
	int		fd;
	t_pcord	**points;

	plan->x = 0;
	plan->y = 0;
	fd = ft_open(str);
	cols_rows_count(fd, plan);
	mem_allocation(plan, &points);
	map_dots(str, plan, points);
	return (points);
}
