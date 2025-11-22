/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:26:14 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/22 00:42:34 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stop_program(t_list *s_in, int ext_val)
{
	if (s_in)
		ft_lstclear(&s_in);
	if (ext_val == EXIT_FAILURE)
		write(2, "Error\n", 6);
	exit(ext_val);
}

t_stacks	init_struct(t_list *stk_a, int size)
{
	t_stacks	data;

	data.stk_a = stk_a;
	data.stk_b = NULL;
	data.size_a = size;
	data.size_b = 0;
	return (data);
}

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1 && stack[i] < stack[i + 1])
		i++;
	return (i == size - 1);
}

int	main(int ac, char **av)
{
	t_list	*s_in;
	int		size;

	if (ac <= 1)
		return (0);
	if (ac == 2 && !av[1][0])
		stop_program(NULL, EXIT_FAILURE);
	size = --ac;
	s_in = NULL;
	if (check_input(av + 1, &size, &s_in, size == 1))
		stop_program(s_in, EXIT_FAILURE);
	if (!size)
		return (0);
	if (size == 1)
		stop_program(s_in, EXIT_SUCCESS);
	if (size <= 5)
		s_in = tiny_sort(init_struct(s_in, size));
	else
		s_in = sort_stack(init_struct(s_in, size));
	stop_program(s_in, EXIT_SUCCESS);
	return (0);
}
