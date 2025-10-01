/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 08:50:57 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/01 10:39:07 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *s);

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	int			found;
	size_t		llen;

	found = 0;
	if (!little || !*little)
		return (big);
	i = 0;
	llen = ft_strlen(little);
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
		return (big + i);
	return (0);
}
