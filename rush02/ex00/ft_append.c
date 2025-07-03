/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemorale <pemorale@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:11:27 by pemorale          #+#    #+#             */
/*   Updated: 2025/06/29 22:39:11 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lib.h"

char	*make_number(int depth, char *input)
{
	char		*nbr;
	int			size;
	int			i;

	i = 0;
	size = ft_strlen(input);
	nbr = (char *) malloc(sizeof(char) * size + 1);
	while (i < size)
	{
		nbr[i] = input[i];
		i++;
	}
	nbr[i] = 0;
	i = 0;
	while (i < depth)
		nbr[size - 1 - i++] = '0';
	return (nbr);
}

char	*allocate_length(char *input, int digits, int size)
{
	int		i;
	char	*length;

	input = input + digits - 1;
	size = ft_strlen(input);
	length = (char *) malloc(sizeof(char) * size + 1);
	length[0] = '1';
	i = 1;
	while (i < size)
		length[i++] = '0';
	length[i] = 0;
	return (length);
}

char	*fill(char *res, char *m1, char *m2)
{
	int	i;

	i = 0;
	while (m1[i])
	{
		res[i] = m1[i];
		i++;
	}
	if (*m1)
		res[i++] = ' ';
	while (*m2)
	{
		res[i++] = *m2;
		m2++;
	}
	res[i] = '\0';
	free(m1);
	return (res);
}

char	*ft_append(char *m1, char *m2)
{
	int		m1_l;
	int		m2_l;
	char	*res;

	m1_l = ft_strlen(m1);
	m2_l = ft_strlen(m2);
	res = malloc(sizeof(char) * (m1_l + m2_l + 2));
	return (fill(res, m1, m2));
}
