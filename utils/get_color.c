/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 23:14:51 by recherra          #+#    #+#             */
/*   Updated: 2024/03/29 23:14:54 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	to_lower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

static int	hex_to_de(char *str)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	to_lower(str);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			number = number * 16;
			number = number + (str[i] - '0');
		}
		else if (str[i] >= 'a' && str[i] <= 'f')
		{
			number = number * 16;
			number = number + 10;
			number = number + (str[i] - 'a');
		}
		i++;
	}
	return (number);
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
	int		color;
	char	*color_str;

	color_str = ft_strchr(point, ',');
	color = 0xffffff;
	if (color_str)
	{
		if (is_all_digits(color_str + 1))
			color = ft_atoi(color_str + 1);
		else
			color = hex_to_de(color_str);
	}
	return (color);
}
