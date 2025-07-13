/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sargevor <sargevor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:28:56 by sargevor          #+#    #+#             */
/*   Updated: 2025/02/11 16:29:16 by sargevor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new_node;
	void	*new_content;

	res = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (ft_lstclear(&res, del), NULL);
		new_node = ft_lstnew(new_content);
		if (!new_node)
			return (del(new_content), ft_lstclear(&res, del), NULL);
		ft_lstadd_back(&res, new_node);
		lst = lst->next;
	}
	return (res);
}
