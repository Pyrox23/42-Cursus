/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 08:50:57 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/04 16:22:50 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	int			found;
	size_t		llen;

	found = 0;
	if (!little)
		return (NULL);
	if (!*little)
		return ((char *) big);
	i = 0;
	llen = ft_strlen(little) - 1;
	while (i + llen < len && !found && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
			j++;
		if (!little[j])
			found = 1;
		else
			i++;
	}
	if (found)
		return ((char *) big + i);
	return (NULL);
}
