/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 23:14:51 by recherra          #+#    #+#             */
/*   Updated: 2024/03/29 23:14:54 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static int	power(int base, int exp)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < exp)
	{
		result *= base;
		i++;
	}
	return (result);
}


static int hex_to_de(char *str) {
    int i;
    int j;
    int     result;
    int     len;
    char    *base;

    j = 0;
    result = 0;
    base = "0123456789abcdef";
    len = ft_strlen(str);
    i = len - 1;
    while (i >= 0) {
        j = 0;
        while (base[j]) {
            if (str[i] == base[j])
            {
                result += j * power(16, len - 1 - i);
                break;
            }
            j++;
        }
        i--;
    }

    return result;
}

//2a

//i = 1;


static int	is_all_digits(char *str)
{
	int	x;
	int	i;

	i = 0;
	x = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			x = 0;
			break ;
		}
		i++;
	}
	return (x);
}

int	get_color(char *point)
{
	int color;
	char *color_str;
	char *fi;

	color_str = ft_strchr(point, ',');
	fi = NULL;
	color = 0xffffff;
	if (color_str)
	{
		if (is_all_digits(color_str + 1))
			color = ft_atoi(color_str + 1);
		else
		{
			fi = ft_strtrim(color_str, ",0x");
            color = hex_to_de(fi);
		}
	}

    free(fi);
	return (color);
}