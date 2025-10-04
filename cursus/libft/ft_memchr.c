/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:01:59 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/09/30 16:01:59 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*mem;
	size_t			i;
	unsigned char	*occ;

	if (!s)
		return (NULL);
	occ = NULL;
	mem = (unsigned char *) s;
	i = 0;
	while (!occ && i < n)
	{
		if (mem[i] == c)
			occ = mem + i;
		i++;
	}
	return ((void *) occ);
}
