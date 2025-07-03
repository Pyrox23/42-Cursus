/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:17:49 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/07/03 12:38:01 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

char	*ft_strdup(char *src)
{
	char			*dup;
	unsigned int	i;
	unsigned int	len;

	len = 0;
	i = 0;
	if (!src)
		return (NULL);
	while (src[len] != 0)
		len++;
	dup = (char *) malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (dup);
	while (src[i] != 0)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

void	free_obj(t_stock_str *list, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(list[i++].copy);
	free(list);
	return ;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*list;
	int			len;
	int			i;

	if (av == NULL || ac == 0)
		return (NULL);
	list = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (list == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		len = 0;
		while (av[i] && av[i][len] != 0)
			len++;
		list[i].size = len;
		list[i].str = av[i];
		list[i].copy = ft_strdup(av[i]);
		if (!list[i].copy)
			return (free_obj(list, i), NULL);
		i++;
	}
	list[i].str = 0;
	return (list);
}
