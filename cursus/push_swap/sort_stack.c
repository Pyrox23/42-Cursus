/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:07:02 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/29 00:15:39 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	find_extremes(int *stack, int *lo, int *hi, int size)
{
	int	i;

	i = 0;
	while (i < stack)
	{

	}
}
May come back to this idea */

//mode: 0 = asc, any other int = desc
int	is_sorted(int *lst, int size, int mode)
{
	int	i;

	i = 1;
	if (!mode)
	{
		while (i < size && lst[i - 1] < lst[i])
			i++;
		return (i == size);
	}
	while (i < size && lst[i - 1] > lst[i])
		i++;
	return (i == size);
}

void	sort_stack(int *s_in, int *s_tmp, int size)
{
	int	pop;


	//stop_program(s_in, s_tmp, EXIT_SUCCESS);
}
