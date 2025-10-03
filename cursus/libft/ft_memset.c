/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:43:36 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/09/30 12:43:36 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ls;

	if (!s)
		return (s);
	i = 0;
	ls = (char *) s;
	while (i < n)
	{
		ls[i] = c;
		i++;
	}
	return (s);
}
