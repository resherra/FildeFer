/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resherra <resherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:45:37 by recherra          #+#    #+#             */
/*   Updated: 2024/01/03 18:38:51 by resherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = ft_calloc(len + 1, sizeof(char));
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
	return (res);
}
