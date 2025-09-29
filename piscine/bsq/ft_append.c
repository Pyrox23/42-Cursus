/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:28:59 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/07/02 15:31:23 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"

unsigned long long	ft_strlen(char *str)
{
	unsigned long long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*fill(char *res, char *m1, char *m2)
{
	unsigned long long	i;

	i = 0;
	while (m1[i])
	{
		res[i] = m1[i];
		i++;
	}
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
	unsigned long long		m1_l;
	unsigned long long		m2_l;
	char					*res;

	m1_l = ft_strlen(m1);
	m2_l = ft_strlen(m2);
	res = malloc(sizeof(char) * (m1_l + m2_l + 1));
	return (fill(res, m1, m2));
}
