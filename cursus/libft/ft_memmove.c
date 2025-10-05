/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:29:25 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/05 17:49:54 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*fr;
	unsigned char	*to;
	size_t			i;

	if (!dest || !src || !len)
		return (dest);
	i = 0;
	fr = (unsigned char *) src;
	to = (unsigned char *) dest;
	if (fr > to)
	{
		while (++i < len + 1)
			to[i - 1] = fr[i - 1];
	}
	else
	{
		while (i < len)
		{
			to[len - i - 1] = fr[len - i - 1];
			i++;
		}
	}
	return (dest);
}
