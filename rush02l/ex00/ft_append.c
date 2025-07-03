/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pemorale <pemorale@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:11:27 by pemorale          #+#    #+#             */
/*   Updated: 2025/06/29 20:20:53 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

char	*fill(char *res, char *m1, char *m2)
{
	int i;

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
	//free(m1);
	//free(m2);
	return (res);
}

char	*ft_append(char *m1, char *m2)
{
	int 	m1_l;
	int 	m2_l;
	char	*res;

	m1_l = ft_strlen(m1);
	m2_l = ft_strlen(m2);
	res = malloc(sizeof(char) * (m1_l + m2_l + 2));
	return	(fill(res, m1, m2));
}
