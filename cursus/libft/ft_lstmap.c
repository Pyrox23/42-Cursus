/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 13:09:19 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/05 19:23:53 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*node;
	int		stop;

	if (!lst || !f || !del)
		return (NULL);
	stop = 0;
	root = NULL;
	while (lst && !stop)
	{
		node = ft_lstnew(f(lst->content));
		if (!node || !node->content)
		{
			stop = 1;
			ft_lstclear(&root, del);
		}
		else
			ft_lstadd_back(&root, node);
		lst = lst->next;
	}
	return (root);
}
