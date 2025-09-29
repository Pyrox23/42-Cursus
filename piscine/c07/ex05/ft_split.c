/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:05:30 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/24 16:23:28 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str, char *charset);

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	if (str != 0)
	{
		while (str[len] != 0)
			len++;
	}
	return (len);
}

int	is_splitter(char c, char *charset)
{
	int		found;

	found = 0;
	while (*charset != 0 && found == 0)
	{
		if (*charset == c)
			found = 1;
		charset++;
	}
	return (found);
}

char	**split_str(char *str, char *charset, char **arr)
{
	int		i;

	i = 0;
	while (*str != 0)
	{
		while (is_splitter(*str, charset) == 1 && *str != 0)
			str++;
		if (*str != 0)
			arr[i++] = str;
		while (is_splitter(*str, charset) != 1 && *str != 0)
			str++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	char		**arr;

	arr = (char **) malloc(sizeof(char) * (ft_strlen(str) / 2 + 1) + 1);
	if (str == 0 || *str == 0)
	{
		arr[0] = 0;
		return (arr);
	}
	if (charset == 0 || *charset == 0)
	{
		arr[0] = str;
		arr[1] = 0;
		return (arr);
	}
	split_str(str, charset, arr);
	return (arr);
}
