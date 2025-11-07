/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:46:28 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/07 19:14:37 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ls;

	i = 0;
	ls = (char *) s;
	while (i < n)
	{
		ls[i] = c;
		i++;
	}
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	char	*occ;
	size_t	i;
	char	ch;

	occ = NULL;
	i = 0;
	ch = (char) c;
	while (!occ && s[i])
	{
		if (s[i] == ch)
			occ = (char *) s + i;
		i++;
	}
	if (!occ && s[i] == ch)
		occ = (char *) s + i;
	return (occ);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	tsize;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	tsize = nmemb * size;
	mem = malloc(tsize);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, tsize);
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2);
	join = (char *) ft_calloc(size + 1, sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = 0;
	return (join);
}
