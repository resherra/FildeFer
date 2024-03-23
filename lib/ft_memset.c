/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:28:26 by recherra          #+#    #+#             */
/*   Updated: 2023/12/29 17:19:07 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;

	p = s;
	ch = c;
	while (n)
	{
		*p++ = ch;
		n--;
	}
	return (s);
}
