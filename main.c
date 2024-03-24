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

// int ext_checker(char *arg)
// {
//
// }

void parse()
{
	
}

int main(int ac, char **av)
{
	int fd;
	
	//check the number of args
	if (ac != 2)
	{
		printf("more/less arguments");
		return 0;
	}
	//args validation
	if (ft_strlen(av[1]) <= 4 || !ft_strnstr(av[1], ".fdf", ft_strlen(av[1])))	
	{
		printf("invalid file");
		return 0;
	}
	fd = open(av[1], O_RDONLY);
	char *str;
	while ((str = get_next_line(fd)))
	{
		printf("%s\n", str);
	}
	
}