/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 00:21:25 by recherra          #+#    #+#             */
/*   Updated: 2024/03/30 00:21:27 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static int	rows_count(char *line)
{
	int	rows;

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
	return (rows);
}

void	cols_rows_count(char *map, t_map_size *plan)
{
	int		fd;
    int first_row;
    char	*str;



    first_row = 0;
	str = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit(1);
	while ((str = get_next_line(fd)))
	{
		//to calculate the rows only for the first time
        plan->x = rows_count(str);
        if (plan->y == 0)
        {
            first_row = plan->x;
        }
        if (plan->x != first_row)
        {
            printf("the map is not rectangle\n");
            exit(1);
        }
		plan->y++;
		free(str);
    }
	close(fd);
}

void	mem_allocation(t_map_size *plan, t_pcord ***points)
{
	int	i;

	i = 0;
	*points = malloc(plan->y * sizeof(t_pcord *));
	if (*points == NULL)
	{
		printf("allocation problem");
		exit(1);
	}
	while (i < plan->y)
	{
		(*points)[i] = malloc(plan->x * sizeof(t_pcord));
		if ((*points)[i] == NULL)
		{
            while (i--)
                free((*points)[i]);
            free(*points);
            free(plan);
            exit(1);
        }
		i++;
	}
}

void	map_dots(char *file, t_map_size *plan, t_pcord ***points)
{
	char **dots;
	char *str;
	int fd;
	int i;
	int j;

	i = 0;
	j = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("open problem");
		exit(1);
	}
	while ((str = get_next_line(fd)) && (dots = ft_split(str, ' '))
		&& j < plan->y)
	{
		i = 0;

		while (dots[i])
		{
			(*points)[j][i].x = i;
			(*points)[j][i].y = j;
			(*points)[j][i].z = ft_atoi(dots[i]);
			(*points)[j][i].color = get_color(dots[i]);
			free(dots[i]);
			i++;
		}
		free(dots);
		free(str);
		j++;
	}
	close(fd);
}