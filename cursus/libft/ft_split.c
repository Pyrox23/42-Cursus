/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:03:28 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/02 21:33:03 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_words(const char *s, char c)
{
	size_t	arr_len;
	size_t	i;

	arr_len = 0;
	i = 0;
	if (!c)
		return (2);
	else
	{
		while (s[i])
		{
			while (s[i] == c)
				i++;
			if (s[i])
				arr_len++;
			while (s[i] != c)
				i++;
		}
	}
	return (arr_len + 1);
}

static size_t	alloc_word(char **arr, const char *s, char c)
{
	size_t	word_len;
	size_t	i;

	word_len = 0;
	while (s[word_len] && s[word_len] != c)
		word_len++;
	arr[0] = (char *) ft_calloc(word_len + 1, sizeof(char));
	if (arr[0])
	{
		i = 0;
		while (i < word_len)
		{
			arr[0][i] = s[i];
			i++;
		}
		arr[0][i] = 0;
	}
	return (word_len);
}

static void	free_list(char ***arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(arr[0][i++]);
	free(arr[0]);
	arr = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	arr_len;
	size_t	i;
	size_t	j;

	arr_len = get_words(s, c);
	arr = (char **) ft_calloc(arr_len, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && arr)
	{
		if (s[i] != c)
		{
			i += alloc_word(&arr[j], s, c);
			if (!arr[j++])
				free_list(&arr, arr_len);
		}
		else
			i++;
	}
	if (arr)
		arr[j] = NULL;
	return (arr);
}
