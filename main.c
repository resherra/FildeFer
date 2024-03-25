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
	}
	printf("rows %d", *x);
}

int main(int ac, char **av)
{
	t_pcord **cords;
	int fd;
	char *str;

	int i = 0;
	int x = 0;
	int y = 0;

	// validate the map
	map_checker(ac, av[1]);

	// width and height of the map
	cols_rows_count(av[1], &x, &y);
}


// int main(int ac, char **av)
// {
// 	int fd = open(av[1], O_RDONLY);
// 	char *str;
// 	while ((str = get_next_line(fd)))
// 		printf("%s", str);
// }