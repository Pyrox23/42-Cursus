/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:07:53 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/06 01:25:31 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_realloc(t_minitalk *g_data)
{
	char	*aux;

	aux = malloc((g_data->len * 2) * sizeof(char));
	if (!aux)
		return (1);
	ft_memmove(aux, g_data->str, g_data->len);
	free(g_data->str);
	g_data->str = aux;
	g_data->dummy = g_data->str + g_data->len;
	g_data->len *= 2;
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

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*fr;
	unsigned char	*to;
	size_t			i;

	if (!dest || !src || !len)
		return (dest);
	i = 0;
	fr = (unsigned char *) src;
	to = (unsigned char *) dest;
	if (fr > to)
	{
		while (++i < len + 1)
			to[i - 1] = fr[i - 1];
	}
	else
	{
		while (i < len)
		{
			to[len - i - 1] = fr[len - i - 1];
			i++;
		}
	}
	return (dest);
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
