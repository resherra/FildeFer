/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:59:33 by recherra          #+#    #+#             */
/*   Updated: 2023/12/31 16:39:12 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*s;
	char	ac;

	s = (char *)str;
	ac = c;
	while (*s)
	{
		if (*s == ac)
			return (s);
		s++;
	}
	if (ac == '\0')
		return (s);
	return (NULL);
}
