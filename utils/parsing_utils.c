/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 00:21:25 by recherra          #+#    #+#             */
/*   Updated: 2024/03/30 00:21:27 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

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

void	cols_rows_count(int fd, t_map_size *plan)
{
	int		first_row;
	char	*str;

	first_row = 0;
	str = get_next_line((fd));
	while (str)
	{
		plan->x = rows_count(str);
		if (plan->y == 0)
			first_row = plan->x;
		if (plan->x != first_row)
            print_error("Fil de Fer: the map columns are not equal.\n");
        free(str);
        str = get_next_line(fd);
		plan->y++;
    }
	close(fd);
}

void	mem_allocation(t_map_size *plan, t_pcord ***points)
{
	int	i;

	i = 0;
	*points = malloc(plan->y * sizeof(t_pcord *));
	if (*points == NULL)
		exit(1);
	while (i < plan->y)
	{
		(*points)[i] = malloc(plan->x * sizeof(t_pcord));
		if ((*points)[i] == NULL)
			exit(1);
		i++;
	}
}

void	fill(t_pcord ***points, char **dots, int i, int j)
{
	(*points)[j][i].x = i;
	(*points)[j][i].y = j;
	(*points)[j][i].z = ft_atoi(dots[i]);
	(*points)[j][i].color = get_color(dots[i]);
	free(dots[i]);
}

void	map_dots(char *file, t_map_size *plan, t_pcord ***points)
{
	char	**dots;
	char	*str;
	int		fd;
	int		j;
	int		i;

	j = 0;
	fd = ft_open(file);
	str = get_next_line(fd);
	while (str && j < plan->y)
	{
		dots = ft_split(str, ' ');
		i = 0;
		while (dots && dots[i])
		{
			fill(points, dots, i, j);
			i++;
		}
		free(dots);
		free(str);
		j++;
		str = get_next_line(fd);
	}
	close(fd);
}
