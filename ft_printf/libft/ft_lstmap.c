/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnam <tnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:17:24 by tnam              #+#    #+#             */
/*   Updated: 2022/11/22 11:17:24 by tnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*next_node;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (0);
	first_node = ft_lstnew(f(lst->content));
	if (first_node == 0)
		return (0);
	next_node = lst->next;
	while (next_node)
	{
		new_node = ft_lstnew(f(next_node->content));
		if (new_node == 0)
		{
			ft_lstclear(&first_node, del);
			return (0);
		}
		ft_lstadd_back(&first_node, new_node);
		next_node = next_node->next;
	}
	return (first_node);
}
