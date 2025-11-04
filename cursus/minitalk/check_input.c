/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:43:03 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/04 15:07:47 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	check_limits(char *nb)
{
	size_t	ln;
	char	sign;

	ln = ft_strlen(nb);
	if (ln > 10)
	{
		sign = nb[0];
		while (nb && *nb == '0' && *(nb + 1) == '0')
			nb++;
		if (sign == '-')
			*nb = sign;
		else
			nb++;
		ln = ft_strlen(nb);
	}
	if (nb[0] != '-')
		return (ln > 10 || (ln == 10 && ft_strncmp(I_MAX, nb, 10) < 0));
	return (ln--, ln > 10 || (ln == 10 && ft_strncmp(I_MIN, nb + 1, 10) < 0));
}

int	check_input(char *str, int *flag)
{
	int	i;
	int	err;

	if (!*str)
		return (*flag = 1, 0);
	i = 0;
	err = 0;
	while (str[i] && !err)
	{
		if ((str[i] == '-' || str[i] == '+') && i == 0 && str[i + 1])
			i++;
		err = !ft_isdigit(str[i++]);
	}
	if (!err && !check_limits(str))
		return (ft_atoi(str));
	return (*flag = 1, 0);
}
