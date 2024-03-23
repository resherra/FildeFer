/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resherra <resherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:45:45 by recherra          #+#    #+#             */
/*   Updated: 2024/01/05 23:31:46 by resherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;
	int		is_diff;
	size_t	tf_len;

	i = 0;
	tf_len = ft_strlen(to_find);
	if (!tf_len)
		return ((char *)(str));
	if (!str && !len)
		return (NULL);
	while (str[i] && len)
	{
		if ((str[i] == to_find[0]) && tf_len <= len)
		{
			is_diff = ft_strncmp(str + i, to_find, tf_len);
			if (is_diff == 0)
				return ((char *)(str + i));
		}
		i++;
		len--;
	}
	return (NULL);
}
