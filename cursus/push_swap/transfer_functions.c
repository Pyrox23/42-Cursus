/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:02:27 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/31 18:25:43 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stacks *dt)
{
	while (dt->top_b < dt->max_size)
		push(dt, 1);
}

void	check_ss(t_stacks *dt)
{
	int	sa;
	int	sb;
	int	nb;

	nb = 0;
	if (dt->top_a + 1 < dt->max_size)
		nb = (dt->stk_a[dt->top_a] / dt->dgt_ref) % 10;
	sa = (nb && dt->stk_a[dt->top_a] > dt->stk_a[dt->top_a + 1]);
	nb = 0;
	if (dt->top_b + 1 < dt->max_size)
		nb = (dt->stk_b[dt->top_b + 1] / dt->dgt_ref) % 10;
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

	ref = dt->top_a;
	while (ref < dt->max_size && !is_sorted(dt, dt->stk_a, 0))
	{
		nb = (dt->stk_a[dt->top_a] / dt->dgt_ref) % 10;
		if (nb < 0)
		{
			check_ss(dt);
			push(dt, 0);
			check_ss(dt);
		}
		else
		{
			check_ss(dt);
			check_rr(dt);
		}
		ref++;
	}
	dt->dgt_ref /= 10;
}

void	transfer_to_tmp(t_stacks *dt)
{
	int	ref;
	int	nb;

	ref = dt->top_a;
	while (ref < dt->max_size && !is_sorted(dt, dt->stk_a, 0))
	{
		nb = (dt->stk_a[dt->top_a] / dt->dgt_ref) % 10;
		if (nb > 0)
		{
			check_ss(dt);
			push(dt, 0);
			check_ss(dt);
		}
		else
		{
			check_ss(dt);
			check_rr(dt);
		}
		ref++;
	}
	dt->dgt_ref *= 10;
}
