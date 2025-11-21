/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 01:32:34 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/21 20:58:50 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*node;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		node = *lst;
		*lst = (*lst)->next;
		free(node);
	}
	*lst = NULL;
}

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = (t_list *) ft_calloc(1, sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->key = content;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst)
		return ;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next)
		node = node->next;
	node->next = new;
}

int	*copy_stack(t_list *stack, int size)
{
	int	i;
	int	*lst;

	lst = (int *) malloc(size * sizeof(int));
	if (!lst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		lst[i++] = stack->content;
		stack = stack->next;
	}
	return (lst);
}
