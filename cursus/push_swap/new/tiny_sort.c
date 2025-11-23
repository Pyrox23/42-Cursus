/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:45:43 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/23 03:32:00 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stacks *data)
{
	if (data->stk_a->content > data->stk_a->next->content)
		swap(data, STK_A);
}

void	sort_3(t_stacks *data)
{
	t_list	*node;
	int		i;
	int		max;
	int		pos;

	i = 1;
	pos = 0;
	node = data->stk_a->next;
	max = data->stk_a->content;
	while (i < 3)
	{
		if (node->content > max)
		{
			pos = i;
			max = node->content;
		}
		node = node->next;
		i++;
	}
	if (pos == 0)
		rotate(data, STK_A);
	else if (pos == 1)
		reverse_rotate(data, STK_A);
	sort_2(data);
}

t_list	find_min(t_stacks *data)
{
	t_list	*node;
	int		i;
	t_list	param;

	i = 1;
	param.key = 0;
	node = data->stk_a->next;
	param.content = data->stk_a->content;
	while (i < data->size_a)
	{
		if (node->content < param.content)
		{
			param.key = i;
			param.content = node->content;
		}
		node = node->next;
		i++;
	}
	return (param);
}

void	sort_45(t_stacks *data)
{
	t_list	param;

	while (data->size_a > 3)
	{
		param = find_min(data);
		if (param.key > data->size_a / 2)
		{
			while (data->stk_a->content != param.content)
				reverse_rotate(data, STK_A);
		}
		else
		{
			while (data->stk_a->content != param.content)
				rotate(data, STK_A);
		}
		push(data, STK_B);
	}
	sort_3(data);
	while (data->size_b)
		push(data, STK_A);
}

t_list	*tiny_sort(t_stacks data)
{
	int	*aux;

	aux = copy_stack(data.stk_a, data.size_a);
	if (!aux)
		stop_program(data.stk_a, EXIT_FAILURE);
	if (!is_sorted(aux, data.size_a))
	{
		if (data.size_a == 2)
			sort_2(&data);
		else if (data.size_a == 3)
			sort_3(&data);
		else
			sort_45(&data);
	}
	free(aux);
	return (data.stk_a);
}
