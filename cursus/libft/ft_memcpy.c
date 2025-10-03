/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:10:02 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/09/30 15:10:02 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*fr;
	char	*to;
	size_t	i;

	if (!dest || !src)
		return (dest);
	fr = (char *) src;
	to = (char *) dest;
	i = 0;
	while (i < n)
	{
		to[i] = fr[i];
		i++;
	}
	return (dest);
}
