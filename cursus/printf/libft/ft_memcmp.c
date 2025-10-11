/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:11:31 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/04 15:17:12 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;
	int				check;

	if (!n)
		return (0);
	i = 0;
	c1 = (unsigned char *) b1;
	c2 = (unsigned char *) b2;
	check = 0;
	while (!check && i < n)
	{
		check = c1[i] - c2[i];
		i++;
	}
	if (!check && i < n)
		return (c1[i] - c2[i]);
	return (check);
}
