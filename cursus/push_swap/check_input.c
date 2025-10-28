/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:43:03 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/28 21:08:42 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_limits(char *nb)
{
	size_t	ln;
	char	sign;

	ln = ft_strlen(nb);
	if (ln > 10)
	{
		sign = nb[0];
		while (nb && *nb == '0' && *(nb + 1) == '0')
			nb++;
		if (sign == '-')
			*nb = sign;
		else
			nb++;
		ln = ft_strlen(nb);
	}
	if (nb[0] != '-')
		return (ln > 10 || (ln == 10 && ft_strncmp(I_MAX, nb, 10) < 0));
	return (ln--, ln > 10 || (ln == 10 && ft_strncmp(I_MIN, nb + 1, 10) < 0));
}

static int	check_duplicate(int *ls, int dup, int size)
{
	int	i;
	int	found;

	found = 0;
	i = 0;
	while (i < size && !found)
		found = (ls[i++] == dup);
	return (found);
}

static int	str_is_int(char *str)
{
	int	i;
	int	err;

	if (!*str)
		return (1);
	i = 0;
	err = 0;
	while (str[i] && !err)
	{
		if ((str[i] == '-' || str[i] == '+') && i == 0 && str[i + 1])
			i++;
		err = !ft_isdigit(str[i++]);
	}
	if (!err)
		return (check_limits(str));
	return (err);
}

int	*check_input(char **ls, int size)
{
	int	*stack;
	int	i;
	int	err;

	stack = (int *) malloc(size * sizeof(int));
	if (!stack)
		return (NULL);
	i = 0;
	err = 0;
	while (i < size && !err)
	{
		err = str_is_int(ls[i]);
		if (!err)
		{
			stack[i] = ft_atoi(ls[i]);
			err = check_duplicate(stack, stack[i], i);
		}
		i++;
	}
	if (err)
		return (free(stack), NULL);
	return (stack);
}
