/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:01:48 by recherra          #+#    #+#             */
/*   Updated: 2024/01/04 13:05:13 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = dst;
	s = src;
	if (!dst && !src)
		return (dst);
	if (src == dst)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
