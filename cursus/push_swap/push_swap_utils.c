/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:10:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/28 20:20:22 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	atoi_rec(const char *str, int digit)
{
	int	nbr;
	int	i;

	if (digit == 0)
		return (0);
	i = 0;
	nbr = *str - '0';
	while (i < digit - 1)
	{
		nbr *= 10;
		i++;
	}
	return (nbr + atoi_rec(++str, --digit));
}

int	ft_atoi(const char *nptr)
{
	int	dgt;
	int	nbr;
	int	pos;

	dgt = 0;
	pos = 0;
	nbr = 1;
	while (nptr[pos] == ' ' || (nptr[pos] >= '\t' && nptr[pos] <= '\r'))
		pos++;
	if (nptr[pos] == '-' || nptr[pos] == '+')
	{
		if (nptr[pos] == '-')
			nbr = -1;
		pos++;
	}
	while (nptr[pos + dgt] <= '9' && nptr[pos + dgt] >= '0')
		dgt++;
	nbr *= atoi_rec(nptr + pos, dgt);
	return (nbr);
}
