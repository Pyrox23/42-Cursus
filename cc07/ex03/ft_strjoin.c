/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:49:04 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/30 17:11:16 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

unsigned long	ft_strlen(char *str)
{
	unsigned long	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned long		dest_len;
	unsigned long		i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != 0)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char			*str;
	int				i;
	unsigned long	len;

	if (size <= 0 || !strs)
	{
		str = (char *) malloc(sizeof(char) * 1);
		str[0] = 0;
		return (str);
	}
	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	str = (char *) malloc(sizeof(char) * len + ft_strlen(sep) * (size - 1) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i++]);
		if (i != size && sep)
			ft_strcat(str, sep);
	}
	return (str);
}
