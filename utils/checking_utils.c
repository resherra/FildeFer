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

void ft_putstr(char *s)
{
    int	i;

    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
}

void	map_checker(int ac, char *map)
{
    int len;

    if (ac != 2)
	{
        ft_putstr("more/less arguments\n");
        exit(1);

	}
    len = ft_strlen(map);
    if (!ft_strnstr(map + (len - 4), ".fdf", 4))
	{
        ft_putstr("invalid file\n");
		exit(1);
	}
}
