/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:04:17 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/21 19:37:56 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_dirs(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	swap(t_stacks *data, int stack)
{
	if (stack == STK_A && data->stk_a && data->stk_a->next)
	{
		swap_dirs(&data->stk_a->content, &data->stk_a->next->content);
		swap_dirs(&data->stk_a->key, &data->stk_a->next->key);
		write(1, "sa\n", 3);
	}
	else if (stack == STK_B && data->stk_b && data->stk_b->next)
	{
		swap_dirs(&data->stk_b->content, &data->stk_b->next->content);
		swap_dirs(&data->stk_b->key, &data->stk_b->next->key);
		write(1, "sb\n", 3);
	}
}

void	push(t_stacks *data, int stack)
{
	t_list	*node;

	if (stack == STK_A && data->stk_b && data->size_b)
	{
		node = data->stk_b;
		data->stk_b = data->stk_b->next;
		ft_lstadd_front(&data->stk_a, node);
		data->size_a++;
		data->size_b--;
		write(1, "pa\n", 3);
	}
	else if (stack == STK_B && data->stk_a && data->size_a)
	{
		node = data->stk_a;
		data->stk_a = data->stk_a->next;
		ft_lstadd_front(&data->stk_b, node);
		data->size_b++;
		data->size_a--;
		write(1, "pb\n", 3);
	}
}

void	rotate(t_stacks *data, int stack)
{
	t_list	*node;

	if (stack == STK_A && data->stk_a && data->stk_a->next && data->size_a > 1)
	{
		node = data->stk_a;
		data->stk_a = data->stk_a->next;
		node->next = NULL;
		ft_lstadd_back(&data->stk_a, node);
		write(1, "ra\n", 3);
	}
	else if (stack == STK_B && data->stk_b && data->stk_b->next
		&& data->size_b > 1)
	{
		node = data->stk_b;
		data->stk_b = data->stk_b->next;
		node->next = NULL;
		ft_lstadd_back(&data->stk_b, node);
		write(1, "rb\n", 3);
	}
}

void	reverse_rotate(t_stacks *data, int stack)
{
	t_list	*node;

	if (stack == STK_A && data->stk_a && data->stk_a->next && data->size_a > 1)
	{
		node = data->stk_a;
		while (node->next->next)
			node = node->next;
		ft_lstadd_front(&data->stk_a, node->next);
		node->next = NULL;
		write(1, "rra\n", 4);
	}
	else if (stack == STK_B && data->stk_b && data->stk_b->next
		&& data->size_b > 1)
	{
		node = data->stk_b;
		while (node->next->next)
			node = node->next;
		ft_lstadd_front(&data->stk_b, node->next);
		node->next = NULL;
		write(1, "rrb\n", 4);
	}
}
