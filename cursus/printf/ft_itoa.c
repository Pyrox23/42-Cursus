/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 20:58:15 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/23 19:26:56 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_power(int base, int exp)
{
	int		i;
	long	ans;

	if (!exp)
		return (1);
	if (!base || exp < 0)
		return (0);
	i = 0;
	ans = 1;
	while (i++ < exp)
		ans *= base;
	return (ans);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			size;
	long		nbr;
	int			i;

	nbr = n;
	size = 1;
	while (nbr / ft_power(10, size))
		size++;
	size += (n < 0);
	str = (char *) ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		nbr *= -1;
		size--;
	}
	size--;
	while (size >= 0)
		str[i++] = (nbr / ft_power(10, size--)) % 10 + '0';
	str[i] = 0;
	return (str);
}
