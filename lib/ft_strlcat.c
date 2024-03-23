/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:33:03 by recherra          #+#    #+#             */
/*   Updated: 2023/12/17 12:51:04 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	i = 0;
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	while (dst[i])
		i++;
	while (src[j] && j < dstsize - dst_len - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}
