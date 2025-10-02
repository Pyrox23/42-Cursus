/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 09:37:22 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/02 14:54:33 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	tsize;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	tsize = nmemb * size;
	mem = malloc(tsize);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, tsize);
	return (mem);
}