/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:07:02 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/30 15:45:09 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_extremes(int *stack, t_radix *data, int size)
{
	int	i;

	i = 0;
	data->lo = stack[0];
	data->hi = stack[0];
	while (i < size)
	{
		if (stack[i] < data->lo)
			data->lo = stack[i];
		if (stack[i] > data->hi)
			data->hi = stack[i];
		i++;
	}
}

void	get_iterations(int *stack, t_radix *data, int size)
{
	int	max;
	int	min;

	find_extremes(stack, data, size);
	max = data->hi;
	min = data->lo;
	while (max && max > min)
	{
		max /= 10;
		data->iters++;
	}
	while (min < -9)
	{
		min /= 10;
		data->iters++;
	}
}

//mode: 0 = asc, any other int = desc
int	is_sorted(int *lst, int size, int mode)
{
	int	i;

	i = 1;
	if (!mode)
		while (i < size && lst[i - 1] < lst[i])
			i++;
	else
		while (i < size && lst[i - 1] > lst[i])
			i++;
	if (i == size)
		printf("stack is sorted in mode %d\n", mode);
	return (i == size);
}

void	sort_stack(int *s_in, int *s_tmp, int size)
{
	int		pop;
	t_radix	data;

	if (is_sorted(s_in, size, 0))
		stop_program(s_in, s_tmp, EXIT_SUCCESS);
	is_sorted(s_in, size, 1);
	pop = 0;
	while (pop < size)
		printf("%d\n", s_in[pop++]);
	get_iterations(s_in, &data, size);
	printf("@data -> min: %d, max: %d, n_iters: %d\n", data.lo, data.hi, data.iters);
	stop_program(s_in, s_tmp, EXIT_SUCCESS);
}
