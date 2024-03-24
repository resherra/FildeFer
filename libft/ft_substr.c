/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:04:03 by recherra          #+#    #+#             */
/*   Updated: 2024/01/03 18:38:15 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (!(*s) || len == 0 || (start) > (unsigned int)(size - 1))
		return (ft_strdup(""));
	if (len <= (size - start))
		str = ft_calloc(len + 1, sizeof(char));
	else
		str = ft_calloc(sizeof(char), (size - start) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while ((i < len) && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
