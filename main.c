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

int main(int ac, char **av)
{
	// int	fd;
	
	// printf("checker %d\n", ext_checker(av[1]));
	if (ac != 2)
	{
		printf("more/less arguments");
		return 0;
	}
	if (strlen(av[1]) <= 4 || !ft_strnstr(av[1], ".fdf", strlen(av[1])))	
	{
		printf("invalid file");
		return 0;
	}	
}