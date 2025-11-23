/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:43:03 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/23 03:09:22 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_limits(char *nb)
{
	size_t	ln;
	char	sign;

	sign = nb[0];
	if (sign == '-' || sign == '+')
		nb++;
	ln = ft_strlen(nb);
	if (ln > 10 && nb[0] == '0')
	{
		while (nb && *nb == '0')
			nb++;
		ln = ft_strlen(nb);
	}
	if (sign == '-')
		return (ln > 10 || (ln == 10 && ft_strncmp(I_MIN, nb, 10) < 0));
	return (ln > 10 || (ln == 10 && ft_strncmp(I_MAX, nb, 10) < 0));
}

static int	check_duplicate(t_list *stack, int dup)
{
	t_list	*node;
	int		found;

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

static int	check_arg(char **arg, int len, int *err, t_list **stack)
{
	t_list	*node;
	int		i;

	i = -1;
	if (!len)
		*err = 1;
	while (++i < len && !*err)
	{
		*err = str_is_int(arg[i]);
		if (!*err)
		{
			node = ft_lstnew(ft_atoi(arg[i]));
			if (node)
			{
				ft_lstadd_back(stack, node);
				*err = check_duplicate(*stack, node->content);
			}
			else
				*err = 1;
		}
	}
	return (len);
}

int	check_input(char **ls, int *size, t_list **stack)
{
	int		i;
	int		err;
	int		len;
	char	**sp;

	i = 0;
	err = 0;
	while (ls[i] && i < *size && !err)
	{
		sp = ft_split(trim(ls[i]), ' ');
		if (!sp)
			err = 1;
		else
		{
			len = get_length(sp);
			*size += check_arg(sp, len, &err, stack) - 1;
			free_list(&sp, len);
		}
		i++;
	}
	return (err);
}
