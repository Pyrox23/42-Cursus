/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:26:41 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/30 21:27:03 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define I_MIN "2147483648"
# define I_MAX "2147483647"
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
//ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
typedef struct s_stacks
{
	int	lo;
	int	hi;
	int	iters;
	int	dgt_ref;
	int	max_size;
	int	*stk_a;
	int	top_a;
	int	*stk_b;
	int	top_b;
}	t_stacks;

void	sort_stack(int *s_in, int *s_tmp, int size);
int		*check_input(char **ls, int size);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
void	stop_program(int *s_in, int *s_tmp, int ext_val);
void	swap(t_stacks *data, int stack, char *print);
void	push(t_stacks *data, int stack);
void	rotate(t_stacks *data, int stack, char *print);
void	reverse_rotate(t_stacks *data, int stack, char *print);
void	push_back(t_stacks *data);

/* void	print_stk(t_stacks *data)
{
	int	i;

	i = data->top_a;
	printf("stk_a:\n");
	while (i < data->max_size)
		printf("%d\n", data->stk_a[i++]);
	printf("stk_b:\n");
	i = data->top_b;
	while (i < data->max_size)
		printf("%d\n", data->stk_b[i++]);
} */

#endif