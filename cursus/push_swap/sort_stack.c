/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:07:02 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/02 23:14:40 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(int *s_in, int *s_tmp, t_stacks *data, int size)
{
	data->lo = s_in[0];
	data->hi = s_in[0];
	data->iters = 0;
	data->dgt_ref = 1;
	data->max_size = size;
	data->stk_a = s_in;
	data->top_a = 0;
	data->stk_b = s_tmp;
	data->top_b = size;
}

void	find_extremes(t_stacks *data)
{
	int	i;

	i = 0;
	while (i < data->max_size)
	{
		if (data->stk_a[i] < data->lo)
			data->lo = data->stk_a[i];
		if (data->stk_a[i] > data->hi)
			data->hi = data->stk_a[i];
		i++;
	}
}

void	get_iterations(t_stacks *data)
{
	int	max;
	int	min;

	find_extremes(data);
	max = data->hi;
	min = data->lo;
	while (max && max > min)
	{
		max /= 10;
		data->iters++;
	}
	while (min < -9 || min > 9)
	{
		min /= 10;
		if (min < -9)
			data->iters++;
		data->dgt_ref *= 10;
	}
}

int	is_sorted(t_stacks *data, int *stack, int mode)
{
	int	i;

	if (stack == data->stk_a)
		i = data->top_a + 1;
	else
		i = data->top_b + 1;
	if (!mode)
		while (i < data->max_size && stack[i - 1] < stack[i])
			i++;
	else
		while (i < data->max_size && stack[i - 1] > stack[i])
			i++;
	return (i == data->max_size);
}

void	sort_stack(int *s_in, int *s_tmp, int size)
{
	t_stacks	data;

	init_data(s_in, s_tmp, &data, size);
	get_iterations(&data);
	while (data.iters && !is_sorted(&data, data.stk_a, 0))
	{
		if (data.lo < 0)
		{
			transfer_to_tmp_neg(&data);
			if (data.dgt_ref == 1)
				data.lo = 0;
		}
		else
			transfer_to_tmp(&data);
		data.iters--;
	}
	while (data.top_b < data.max_size)
		push(&data, 1, 1);
	print_stk(&data);
	stop_program(s_in, s_tmp, EXIT_SUCCESS);
}
