/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:50:20 by recherra          #+#    #+#             */
/*   Updated: 2024/01/04 21:27:58 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;
	size_t	res;

	res = count * size;
	if (size != 0 && count != res / size)
		return (NULL);
	dst = malloc(res);
	if (!dst)
		return (NULL);
	ft_bzero(dst, res);
	return (dst);
}
