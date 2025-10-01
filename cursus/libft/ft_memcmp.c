/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:11:31 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/01 09:28:24 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	memcmp(const void *b1, const void *b2, size_t len);

int	memcmp(const void *b1, const void *b2, size_t len)
{
	char	*c1;
	char	*c2;
	size_t	i;
	int		check;

	if (!len)
		return (0);
	i = 0;
	c1 = (char *) b1;
	c2 = (char *) b2;
	check = 0;
	while (c1[i] && c2[i] && !check && i < len)
	{
		check = c1[i] - c2[i];
		i++;
	}
	if (!check && len)
		return (c1[i] - c2[i]);
	return (check);
}
