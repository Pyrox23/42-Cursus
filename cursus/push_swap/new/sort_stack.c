/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:02:19 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/23 01:22:45 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_keys(t_stacks *data, int *lst)
{
	t_list	*node;
	int		i;

	while (!is_sorted(lst, data->size_a))
	{
		i = 0;
		while (i < data->size_a - 1)
		{
			if (lst[i] > lst[i + 1])
				swap_dirs(&lst[i], &lst[i + 1]);
			i++;
		}
	}
	i = 0;
	while (i < data->size_a)
	{
		node = data->stk_a;
		while (node->content != lst[i])
			node = node->next;
		node->key = i++;
	}
}

void	push_chunks_b(t_stacks *data)
{
	int	chunk;
	int	i;

	chunk = data->size_a / 10 + 11;
	i = chunk;
	while (data->size_a)
	{
		if (data->stk_a->key < i)
		{
			push(data, STK_B);
			if (data->stk_b->key < i - (chunk / 2))
				rotate(data, STK_B);
		}
		else
			rotate(data, STK_A);
		if (data->size_b >= i)
			i += chunk;
	}
}

int	find_max(t_list *stack)
{
	t_list	*node;
	int		max;
	int		pos;
	int		i;

	max = stack->key;
	pos = 0;
	i = 0;
	node = stack;
	while (node)
	{
		if (node->key > max)
		{
			max = node->key;
			pos = i;
		}
		node = node->next;
		i++;
	}
	return (pos);
}

void	push_back(t_stacks *data)
{
	int	max_pos;

	while (data->size_b)
	{
		max_pos = find_max(data->stk_b);
		if (max_pos <= data->size_b / 2)
		{
			while (max_pos > 0)
			{
				rotate(data, STK_B);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < data->size_b)
			{
				reverse_rotate(data, STK_B);
				max_pos++;
			}
		}
		push(data, STK_A);
	}
}

t_list	*sort_stack(t_stacks data)
{
	int	*aux;

	aux = copy_stack(data.stk_a, data.size_a);
	if (!aux)
		stop_program(data.stk_a, EXIT_FAILURE);
	if (!is_sorted(aux, data.size_a))
	{
		assign_keys(&data, aux);
		push_chunks_b(&data);
		push_back(&data);
	}
	free(aux);
	return (data.stk_a);
}
