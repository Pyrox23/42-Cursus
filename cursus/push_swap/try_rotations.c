/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:24:42 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/31 18:29:27 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static void	do_rot(t_stacks *dt, void (*f)(t_stacks*, int, char), char *print)
{
	f(dt, 0, NULL);
	f(dt, 1, print);
}

//-1 is none, 0 is reverse, 1 is normal, 2 is any
static int	check_rotation_type(t_stacks *dt, int *stack, int top)
{
	if (is_sorted(dt, dt->stk_a, 0))
		return (-1);
	if (top + 2 >= dt->max_size)
		return (2);
	if (stack == dt->stk_a)
		return (((stack[top + 1] / dt->dgt_ref) % 10 < (stack[dt->max_size - 1]
					/ dt->dgt_ref) % 10));
	return (((stack[top + 1] / dt->dgt_ref) % 10 > (stack[dt->max_size - 1]
				/ dt->dgt_ref) % 10));
}

void	check_rr(t_stacks *dt)
{
	int	ra;
	int	rb;
	int	eq;

	ra = check_rotation_type(dt, dt->stk_a, dt->top_a);
	rb = check_rotation_type(dt, dt->stk_b, dt->top_b);
	eq = ((ra == 2 || rb == 2 || ra == rb) && ra != -1 && rb != -1);
	if (eq)
	{
		ra = min(ra, rb);
		if (ra)
			do_rot(dt, rotate, "rr\n");
		else
			do_rot(dt, reverse_rotate, "rrr\n");
	}
	if (ra && ra != -1)
		rotate(dt, 1, "ra\n");
	else if (!ra)
		reverse_rotate(dt, 1, "rra\n");
	if (rb && rb != -1)
		rotate(dt, 0, "rb\n");
	else if (!rb)
		reverse_rotate(dt, 0, "rrb\n");
}
