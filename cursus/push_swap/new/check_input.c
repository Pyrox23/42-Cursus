/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:43:03 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/21 02:37:41 by ramo-cou         ###   ########.fr       */
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

static int	check_duplicate(t_list *stack, int dup, int size)
{
	t_list	*node;
	int		found;

	if (!size)
		return (0);
	found = 0;
	node = stack;
	while (node->next && !found)
	{
		found = (node->content == dup);
		node = node->next;
	}
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
		err = !(str[i] >= '0' && str[i] <= '9');
		i++;
	}
	if (!err)
		return (check_limits(str));
	return (err);
}

int	get_length(char **ls)
{
	int	len;

	len = 0;
	while (ls[len])
		len++;
	return (len);
}

int	check_input(char **ls, int *size, t_list **stack, int split)
{
	int		i;
	int		err;
	t_list	*node;

	if (split)
		ls = ft_split(ls[0], ' ');
	*size = get_length(ls);
	i = -1;
	err = 0;
	while (++i < *size && !err)
	{
		err = str_is_int(ls[i]);
		if (!err)
		{
			node = ft_lstnew(ft_atoi(ls[i]));
			if (node)
			{
				ft_lstadd_back(stack, node);
				err = check_duplicate(*stack, node->content, i);
			}
			else
				err = 1;
		}
	}
	return (free_list(&ls, *size, split), err);
}
