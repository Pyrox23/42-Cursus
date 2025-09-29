/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemorale <pemorale@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:32:04 by pemorale          #+#    #+#             */
/*   Updated: 2025/06/29 20:21:08 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		comp;

	comp = 0;
	while (comp == 0 && *s1 != 0 && (*s2 != 0 || *s2 != ':'))
	{
		comp = *s1 - *s2;
		s1++;
		s2++;
	}
	if (comp == 0 && *s2 != ':')
		comp = *s1 - *s2;
	return (comp);
}

char	*find_key(char **dict, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dict[i] && ft_strcmp(str, dict[i]) != 0)
		i++;
	if (!dict[i])
		return (NULL);
	while (dict[i][j] != ':')
		j++;
	j++;
	return (&dict[i][j]);
}
