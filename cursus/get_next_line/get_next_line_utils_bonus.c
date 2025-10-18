/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:37:11 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/18 20:47:07 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ls;

	i = 0;
	ls = (char *) s;
	while (i < n)
	{
		ls[i] = 0;
		i++;
	}
}

size_t	ft_find(char *str, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (i < n && str[i] != '\n')
		i++;
	if (i == n)
		return (0);
	return (i + 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_memmove(char *dest, char *src, size_t len)
{
	size_t			i;

	i = 0;
	if (src > dest)
	{
		while (i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			dest[len - i - 1] = src[len - i - 1];
			i++;
		}
	}
	return ((char *) dest);
}
