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

//#include "libft/libft.h"
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

static int	hex_to_de(char *str)
{
	char	*base;
	char	rev_str[7];
	int		result;
	int		i;
	int		j;

	base = "0123456789abcdef";
	i = ft_strlen(str);
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
				result += j * power(16, i);
			j++;
		}
		i++;
	}
	return (result);
}

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