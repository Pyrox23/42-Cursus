/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:02:27 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/02 23:25:44 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_spot(t_stacks *dt, int *stack)
{
	int	top_val;
	int	top;

	if (stack == dt->stk_b)
		top = dt->top_b;
	else
		top = dt->top_a;
	top_val = stack[top];
	top++;
	while (stack[top] > top_val)
		top++;
	return (top);
}

void	put_top(t_stacks *dt, int sort_top, void (*f1)(t_stacks*, int, char*),
	void (*f2)(t_stacks*, int, char*))
{
	int		aux;
	char	*print;

	aux = sort_top;
	if (f1 == rotate)
		print = "rb\n";
	else
		print = "rrb\n";
	while (aux--)
		f1(dt, 0, print);
	push(dt, 0, 1);
	if (f2 == rotate)
		print = "rrb\n";
	else
		print = "rb\n";
	while (sort_top--)
		f2(dt, 0, print);
}

int	sort_b(t_stacks *dt)
{
	int	sort_top;

	if (!is_sorted(dt, dt->stk_b, 1))
	{
		if (check_top(dt, dt->stk_b, dt->top_b, 1))
			return (push(dt, 1, 0), push(dt, 0, 1), check_rr(dt), 0);
		else
		{
			sort_top = find_spot(dt, dt->stk_b) - dt->top_b;
			if (sort_top == 1)
				return (push(dt, 1, 0), push(dt, 0, 1), check_ss(dt), 0);
			push(dt, 1, 0);
			if (sort_top < (dt->top_b - dt->max_size) / 2)
				put_top(dt, sort_top, rotate, reverse_rotate);
			else
				put_top(dt, sort_top, reverse_rotate, rotate);
		}
	}
	else
		return (push(dt, 1, 0), push(dt, 0, 1), 0);
	return (0);
}

void	check_ss(t_stacks *dt)
{
	int	sa;
	int	sb;
	int	nb;

	nb = 0;
	if (dt->top_a + 1 < dt->max_size)
		nb = dt->stk_a[dt->top_a] / dt->dgt_ref;
	sa = (nb && dt->stk_a[dt->top_a] > dt->stk_a[dt->top_a + 1]);
	nb = 0;
	if (dt->top_b + 1 < dt->max_size)
		nb = dt->stk_b[dt->top_b + 1] / dt->dgt_ref;
	sb = (nb && dt->stk_b[dt->top_b] > dt->stk_b[dt->top_b + 1]);
	if (sa && sb)
	{
		swap(dt, 0, NULL);
		swap(dt, 1, "ss\n");
	}
	else if (sa)
		swap(dt, 1, "sa\n");
	else if (sb)
		swap(dt, 0, "sb\n");
}

void	transfer_to_tmp_neg(t_stacks *dt)
{
	int	ref;
	int	nb;
	int	rot;

	ref = dt->top_a; //Esto no funciona, tienes que mirar si vale la pena rotar o no, en otras palabras, si esta el numero con la referencia que estes viendo
	while (ref < dt->max_size && !is_sorted(dt, dt->stk_a, 0))
	{
		nb = dt->stk_a[dt->top_a] / dt->dgt_ref;
		if (nb < 0 && nb > -10)
		{
			check_ss(dt);
			push(dt, 0, 0);
			sort_b(dt);
		}
		else
		{
			rot = check_rotation_type(dt, dt->stk_a, dt->top_a);
			if (rot != -1 && rot)
				rotate(dt, 1, "ra\n");
			else if (rot != -1)
				reverse_rotate(dt, 1, "rra\n");
		}
		ref++;
		print_stk(dt);
	}
	dt->dgt_ref /= 10;
}

void	transfer_to_tmp(t_stacks *dt)
{
	int	ref;
	int	nb;
	int	rot;

	ref = dt->top_a;
	while (ref < dt->max_size && !is_sorted(dt, dt->stk_a, 0))
	{
		nb = dt->stk_a[dt->top_a] / dt->dgt_ref;
		if (nb > 0 && nb < 10)
		{
			check_ss(dt);
			push(dt, 0, 0);
			sort_b(dt);
		}
		else
		{
			rot = check_rotation_type(dt, dt->stk_a, dt->top_a);
			if (rot != -1 && rot)
				rotate(dt, 1, "ra\n");
			else if (rot != -1)
				reverse_rotate(dt, 1, "rra\n");
		}
		ref++;
		print_stk(dt);
	}
	dt->dgt_ref *= 10;
}
