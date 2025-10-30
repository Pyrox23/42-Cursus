/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:02:27 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/30 21:47:01 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stacks *dt)
{
	while (dt->top_b < dt->max_size)
		push(dt, 1);
}

void	check_ss(t_stacks *data)
{

}

void	check_rr(t_stacks *data)
{
	
}

void	transfer_to_tmp_neg(t_stacks *dt)
{
	int	ref;
	int	nb;

	ref = dt->top_a; //to know what numbers i have seen
	while (ref < dt->max_size && !is_sorted(dt, dt->stk_a, 0))
	{
		nb = dt->stk_a[dt->top_a] / dt->dgt_ref;
		if (nb < 0)
		{
			check_ss(dt); //if ss can be done do it, else do swap if is good
			push(dt, 0);
			check_ss(dt);
		}
		else
		{
			check_ss(dt);
			check_rr(dt); //check for rr, rrr and what rotation is better
		}
		ref++;
	}
	dt->dgt_ref /= 10;
}

void	transfer_to_tmp(t_stacks *dt)
{
	int	ref;
	int	nb;

	ref = dt->top_a; //to know what numbers i have seen
	while (ref < dt->max_size && !is_sorted(dt, dt->stk_a, 0))
	{
		nb = dt->stk_a[dt->top_a] / dt->dgt_ref;
		if (nb < 0)
		{
			check_ss(dt); //if ss can be done do it, else do swap if is good
			push(dt, 0);
			check_ss(dt);
		}
		else
		{
			check_ss(dt);
			check_rr(dt); //check for rr, rrr and what rotation is better
		}
		ref++;
	}
	dt->dgt_ref *= 10;
}
