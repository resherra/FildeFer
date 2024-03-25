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

//count the cols and rows of a map
int rows_count(char *line)
{
	int rows;
	
	rows = 0;
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		if (*line)
			rows++;
		while (*line && *line != ' ')
			line++;
	}
	return rows;
}

void cols_rows_count(char *map, int *x, int *y)
{
	int fd;
	char *str;

	str = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit(1);
	while ((str = get_next_line(fd)))
	{
		*x = rows_count(str); 
		(*y)++;
		free(str);
	}
}

//main
int main(int ac, char **av)
{
	t_pcord **points;
	t_map_size plan;
	int fd;
	char *str;

	int i = 0;
	
	// validate the map
	map_checker(ac, av[1]);

	// cols and rows of the map
	cols_rows_count(av[1], &plan.x, &plan.y);
	
	//points mem allocation
	points = malloc(plan.y * sizeof (t_pcord *));
	if (!points)
		return 0;
	while (i < plan.y)
	{
		points[i] = malloc(plan.x * sizeof(t_pcord));
		if (!points[i])
		{
			//free here;
			exit(1);
		}
		i++;
	}
	
	
	// system("leaks -q a.out");
}



// int main(int ac, char **av)
// {
// 	int fd = open(av[1], O_RDONLY);
// 	char *str;
// 	while ((str = get_next_line(fd)))
// 		printf("%s", str);
// }