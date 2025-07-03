/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:05:30 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/28 20:47:02 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lib.h"

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

void	format_word(char **arr, char *str, char *set, unsigned long long len)
{
	unsigned long long	i;
	unsigned long long	j;

	i = 0;
	j = 0;
	while (str[i] && !is_splitter(str[i], set) && str[i - 1] != ':')
	{
		if (str[i] != ' ')
			arr[0][j++] = str[i++];
		else
			i++;
	}
	while (str[i] && str[i] == ' ')
		i++;
	while (i < len)
	{
		if (str[i] == ' ')
			while (i < len && str[i + 1] == ' ')
				i++;
		arr[0][j++] = str[i++];
	}
	arr[0][j] = 0;
}

unsigned long long	alloc_word(char **arr, char *str, char *set)
{
	unsigned long long	word_len;

	word_len = 0;
	while (str[word_len] && !is_splitter(str[word_len], set))
		word_len++;
	arr[0] = (char *) malloc(sizeof(char) * word_len + 1);
	if (arr[0])
		format_word(arr, str, set, word_len);
	return (word_len);
}

char	**ft_split(char *str, char *charset)
{
	char				**arr;
	unsigned long long	arr_len;
	unsigned long long	i;

	arr_len = 0;
	i = 0;
	while (str[arr_len])
		arr_len++;
	arr_len = arr_len / 2 + 1;
	arr = (char **) malloc(sizeof(char *) * arr_len + 1);
	if (!arr)
		return (NULL);
	while (*str)
	{
		if (!is_splitter(*str, charset))
			str += alloc_word(&arr[i++], str, charset);
		else
			str++;
	}
	arr[i++] = NULL;
	while (i < arr_len)
		free(arr[i++]);
	return (arr);
}
