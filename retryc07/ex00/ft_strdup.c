/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:06:00 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/23 15:55:05 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src);

unsigned int	ft_strlen(char *str)
{
	unsigned int		len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char			*dup;
	unsigned int	i;

	i = 0;
	dup = (char *) malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dup == NULL)
		return (dup);
	while (src[i] != 0)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
