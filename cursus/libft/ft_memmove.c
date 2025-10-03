/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:29:25 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/03 09:31:11 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*fr;
	char	*to;
	size_t	i;

	i = 0;
	fr = (char *) src;
	to = (char *) dest;
	if (fr > to)
	{
		while (i < len)
		{
			to[i] = fr[i];
			i++;
		}
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
