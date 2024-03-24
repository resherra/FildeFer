/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:06:45 by recherra          #+#    #+#             */
/*   Updated: 2024/01/05 23:22:49 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strchr(set, s[i]))
			break ;
		i++;
	}
	return (i);
}

static int	end(char const *s, char const *set, int len, int i)
{
	len--;
	while (len >= 0 && i < len)
	{
		if (!ft_strchr(set, s[len]))
			break ;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		i;
	int		j;
	int		q;
	char	*ret;
	int		size;

	i = 0;
	q = 0;
	if (!s || !set)
		return (NULL);
	i = start(s, set);
	j = end(s, set, ft_strlen(s), i);
	if (ft_strlen(s) == 0)
		return (ft_strdup(""));
	else
		size = (j - i) + 1;
	ret = ft_calloc((size + 1), sizeof(char));
	if (!ret)
		return (NULL);
	while (q < size)
		ret[q++] = s[i++];
	return (ret);
}
