/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:26:39 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/05 17:37:12 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int		found;
	size_t	i;

	found = 0;
	i = 0;
	while (set[i] && !found)
	{
		if (c == set[i])
			found = 1;
		i++;
	}
	return (found);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	start = 0;
	if (!s1)
		return (NULL);
	while (s1[start] && is_set(s1[start], set))
		start++;
	end = start;
	while (s1[end])
		end++;
	if (start == end)
		return (ft_calloc(1, sizeof(char)));
	end--;
	while (start != end && is_set(s1[end], set))
		end--;
	str = (char *) ft_calloc(end - start + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	return (str);
}
