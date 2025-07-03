/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:20:50 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/26 13:11:52 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);

unsigned long	ft_strlen(char *str)
{
	unsigned long	len;

	len = 0;
	while (str != NULL && str[len] != 0)
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int		dest_len;
	unsigned int		i;

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
	unsigned long	full_len;
	int				i;

	if (size <= 0 || strs == NULL)
	{
		str = (char *) malloc(1);
		str[0] = 0;
		return (str);
	}
	full_len = 0;
	i = 0;
	while (i < size)
		full_len += ft_strlen(strs[i++]);
	str = (char *) malloc(full_len + (ft_strlen(sep) * (size - 1)) + 1);
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i++]);
		if (i != size && sep != NULL)
			ft_strcat(str, sep);
	}
	return (str);
}
