/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:26:14 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/29 00:02:47 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stop_program(int *s_in, int *s_tmp, int ext_val)
{
	if (s_in)
		free(s_in);
	if (s_tmp)
		free(s_tmp);
	if (ext_val == EXIT_FAILURE)
		write(2, "Error\n", 6);
	exit(ext_val);
}

int	*init_stack(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
		stack[i++] = 0;
	return (stack);
}

int	main(int ac, char **av)
{
	int	*s_in;
	int	*s_tmp;
	int	i;

	if (ac <= 1)
		return (0);
	s_in = check_input(av + 1, --ac);
	if (!s_in)
		stop_program(NULL, NULL, EXIT_FAILURE);
	if (ac == 1)
		return (0);
	i = 0;
	while (i < ac)
		printf("%d\n", s_in[i++]);
	s_tmp = (int *) malloc(ac * sizeof(int));
	if (!s_tmp)
		stop_program(s_in, NULL, EXIT_FAILURE);
	sort_stack(s_in, init_stack(s_tmp, ac), ac);
	return (0);
}
