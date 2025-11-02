/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:04:17 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/02 22:27:02 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_dirs(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	swap(t_stacks *data, int stack, char *print)
{
	if (stack == 1 && data->top_a < data->max_size - 1)
		swap_dirs(data->stk_a + data->top_a, data->stk_a + data->top_a + 1);
	else if (stack == 0 && data->top_b < data->max_size - 1)
		swap_dirs(data->stk_b + data->top_b, data->stk_b + data->top_b + 1);
	if (print && *print)
		write(1, print, ft_strlen(print));
}

void	push(t_stacks *data, int stack, int print)
{
	int	pop;

	if (stack == 1 && data->top_a)
	{
		pop = data->stk_b[data->top_b];
		data->stk_b[data->top_b++] = 0;
		data->stk_a[--data->top_a] = pop;
	}
	else if (stack == 0 && data->top_b)
	{
		pop = data->stk_a[data->top_a];
		data->stk_a[data->top_a++] = 0;
		data->stk_b[--data->top_b] = pop;
	}
	if (stack == 1 && print)
		write(1, "pa\n", 3);
	else if (stack == 0 && print)
		write(1, "pb\n", 3);
}

void	rotate(t_stacks *data, int stack, char *print)
{
	int	top;

	if (stack == 1)
	{
		top = data->top_a;
		while (top < data->max_size - 1)
		{
			swap_dirs(data->stk_a + top, data->stk_a + top + 1);
			top++;
		}
	}
	else if (stack == 0)
	{
		top = data->top_b;
		while (top < data->max_size - 1)
		{
			swap_dirs(data->stk_b + top, data->stk_b + top + 1);
			top++;
		}
	}
	if (print && *print)
		write(1, print, ft_strlen(print));
}

void	reverse_rotate(t_stacks *data, int stack, char *print)
{
	int	bot;

	if (stack == 1)
	{
		bot = data->max_size - 1;
		while (bot > data->top_a)
		{
			swap_dirs(data->stk_a + bot, data->stk_a + bot - 1);
			bot--;
		}
	}
	else if (stack == 0)
	{
		bot = data->max_size - 1;
		while (bot > data->top_b)
		{
			swap_dirs(data->stk_b + bot, data->stk_b + bot - 1);
			bot--;
		}
	}
	if (print && *print)
		write(1, print, ft_strlen(print));
}
