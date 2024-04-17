/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:31:18 by recherra          #+#    #+#             */
/*   Updated: 2024/02/20 10:44:53 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_ft_strlen(char *s1)
{
	int	i;

	if (!s1 || !(*s1))
		return (0);
	i = 0;
	while (s1[i])
		i++;
	return (i);
}

void	get_ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*get_ft_strdup(char *s1)
{
	char	*str;
	int		len;
	int		i;

	if (!s1 || !(*s1))
		return (NULL);
	i = 0;
	len = get_ft_strlen(s1);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*get_ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1)
		return (get_ft_strdup(s2));
	len = get_ft_strlen(s1) + get_ft_strlen(s2);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (s1[j])
	{
		res[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		res[j + i] = s2[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}

int	ft_trunc(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
