/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:05:30 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/07/02 14:49:26 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str, char *charset);

int	is_splitter(char c, char *charset)
{
	int		found;

	found = 0;
	while (charset && *charset != 0 && found == 0)
	{
		if (*charset == c)
			found = 1;
		charset++;
	}
	return (found);
}

unsigned long long	alloc_word(char **arr, char *str, char *set)
{
	unsigned long long	word_len;
	unsigned long long	i;

	word_len = 0;
	while (str[word_len] && !is_splitter(str[word_len], set))
		word_len++;
	arr[0] = (char *) malloc(sizeof(char) * word_len + 1);
	if (arr[0])
	{
		i = 0;
		while (i < word_len)
		{
			arr[0][i] = str[i];
			i++;
		}
		arr[0][i] = 0;
	}
	return (word_len);
}

void	init_arr(char **arr, unsigned long long arr_len)
{
	unsigned long long	i;

	i = 0;
	while (i < arr_len)
		arr[i++] = NULL;
	return ;
}

char	**ft_split(char *str, char *charset)
{
	char				**arr;
	unsigned long long	arr_len;
	unsigned long long	i;

	arr_len = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[arr_len])
		arr_len++;
	arr_len = arr_len / 2 + 1;
	arr = (char **) malloc(sizeof(char *) * arr_len + 1);
	if (!arr)
		return (NULL);
	init_arr(arr, arr_len);
	while (*str)
	{
		if (!is_splitter(*str, charset))
			str += alloc_word(&arr[i++], str, charset);
		else
			str++;
	}
	while (i < arr_len)
		arr[i++] = NULL;
	return (arr);
}
