/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:10:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/22 19:06:42 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				comp;
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!n)
		return (0);
	comp = 0;
	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (str1[i] && str2[i] && !comp && i < n)
	{
		comp = str1[i] - str2[i];
		i++;
	}
	if (!comp && i < n)
		comp = str1[i] - str2[i];
	return (comp);
}

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

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;
	int	i;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] <= '9' && str[i] >= '0')
		nbr = nbr * 10 + (str[i++] - '0');
	return (nbr * sign);
}

char	*trim(char *s1)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1)
		return (s1);
	while (s1[start] && s1[start] == ' ')
		start++;
	end = start;
	while (s1[end])
		end++;
	if (start == end)
		return (s1[start]);
	end--;
	while (start != end && s1[end] == ' ')
		end--;
	s1[end + 1] = 0;
	return (s1[start]);
}
