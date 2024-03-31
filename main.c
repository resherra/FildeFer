/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:34:46 by recherra          #+#    #+#             */
/*   Updated: 2024/03/23 17:34:48 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

//validate the arguments
void	map_checker(int ac, char *map)
{
	//check the number of args
	if (ac != 2)
	{
		printf("more/less arguments");
		exit(1);
	}
	//args validation
	if (ft_strlen(map) <= 4 || !ft_strnstr(map, ".fdf", ft_strlen(map)))
	{
		printf("invalid file");
		exit(1);
	}
}

//print the map
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

//main
int	main(int ac, char **av)
{
	t_pcord **points;
	t_map_size *plan;

	map_checker(ac, av[1]);

	plan = malloc(sizeof(t_map_size));

	cols_rows_count(av[1], plan);

	mem_allocation(plan, &points);

	map_dots(av[1], plan, &points);

	print(points, plan);

//    free(points);
    for (int i = 0; i < plan->y; i++)
        free(points[i]);
    free(points);
    free(plan);
//	system("leaks -q a.out");
}