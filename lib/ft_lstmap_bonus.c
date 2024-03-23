/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recherra <recherra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:33:01 by recherra          #+#    #+#             */
/*   Updated: 2024/01/04 21:34:07 by recherra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ne;
	t_list	*ne_node;
	void	*ptr;

	ne = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		ptr = f(lst->content);
		ne_node = ft_lstnew(ptr);
		if (!ne_node)
		{
			del(ptr);
			ft_lstclear(&ne, del);
			return (NULL);
		}
		ft_lstadd_back(&ne, ne_node);
		lst = lst->next;
	}
	return (ne);
}
