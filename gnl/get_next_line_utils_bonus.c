/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:14:14 by recherra          #+#    #+#             */
/*   Updated: 2024/02/20 10:45:38 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s1)
{
	int	i;

	if (!s1 || !(*s1))
		return (0);
	i = 0;
	while (s1[i])
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, char *src, int dstsize)
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

char	*ft_strdup(char *s1)
{
	char	*str;
	int		len;
	int		i;

	if (!s1 || !(*s1))
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
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
