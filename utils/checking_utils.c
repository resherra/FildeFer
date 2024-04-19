/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:01:22 by recherra          #+#    #+#             */
/*   Updated: 2024/04/17 17:01:23 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../init.h"

void	map_checker(int ac, char *map)
{
    int len;

    if (ac != 2)
	{
		printf("more/less arguments");
        exit(1);

	}
    len = ft_strlen(map);
    if (!ft_strnstr(map + (len - 4), ".fdf", 4))
	{
        printf("invalid file");
		exit(1);
	}
}
