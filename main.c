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


//depends on plan
void cols_rows_count(char *map, t_map_size *plan)
{
	int fd;
	char *str;

	str = NULL;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit(1);

	while ((str = get_next_line(fd)))
	{
        //to calculate the rows only for the first time
        if (plan->y == 0)
            plan->x = rows_count(str);
        plan->y++;
        free(str);
	}

	close(fd);
}

void print(t_pcord **points, t_map_size *plan)
{
    int i = 0;
    int j = 0;

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

void    mem_allocation(t_map_size *plan, t_pcord ***points)
{
    int i;

    i = 0;
    *points = malloc(plan->y * sizeof(t_pcord *));
    if (*points == NULL)
    {
        printf("allocation problem");
        exit(1);
    }
    while (i < plan->y) {
        (*points)[i] = malloc(plan->x * sizeof(t_pcord));
        if ((*points)[i] == NULL)
        {
            //free here
            exit(1);
        }
        i++;
    }
}

void    map_dots(char *file, t_map_size *plan, t_pcord ***points)
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
    while ((str = get_next_line(fd)) && (dots = ft_split(str, ' ')) && j < plan->y )
    {
        i = 0;
        while (dots[i])
        {
            (*points)[j][i].x = i;
            (*points)[j][i].y = j;
            (*points)[j][i].z = ft_atoi(dots[i]);
            i++;
        }
        j++;
    }
}

int	power(int base, int exp)
{
    int i;
    int result;

    i = 0;
    result = 1;
    while (i < exp)
    {
        result *= base;
        i++;
    }

    return result;
}

int	hx(char *str)
{
    char *base = "0123456789abcdef";
    char rev_str[7];
    int result;
    int i;
    int j;

    i = strlen(str);
    j = 0;
    result = 0;
    while (i)
    {
        i--;
        rev_str[j++] = str[i];
    }
    rev_str[j] = '\0';
    i = 0;
    j = 0;
    while (rev_str[i])
    {
        j = 0;
        while (base[j])
        {
            if (rev_str[i] == base[j])
            {
                result += j * power(16, i);

            }
            j++;
        }
        i++;
    }

    return result;
}



//main
int main(int ac, char **av) {

    int fd;
    int i;
    int j;
    t_pcord **points;
    t_map_size *plan;
    char **dots;

    i = 0;
    // validate the map
    map_checker(ac, av[1]);

    // cols and rows of the map
    plan = malloc(sizeof(t_map_size));

    cols_rows_count(av[1], plan);

    //points mem allocation
    mem_allocation(plan, &points);

    //map dots
    map_dots(av[1], plan, &points);

    //print map
    print(points, plan);

    //    system("leaks -q a.out");
}