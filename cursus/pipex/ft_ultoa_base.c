/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:39:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/23 23:48:29 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_digits(size_t nb, int base)
{
	int	dgt;

	if (!nb)
		return (1);
	dgt = 0;
	while (nb)
	{
		nb /= base;
		dgt++;
	}
	return (dgt);
}

static void	ft_ultoa_base_rec(size_t nb, char *base, size_t length)
{
	if (nb > length - 1)
		ft_ultoa_base_rec(nb / length, base, length);
	write(1, &base[nb % length], 1);
}

int	ft_ultoa_base(size_t nbr, char *base)
{
	int		i;
	int		len;

	if (!base)
		return (0);
	len = ft_strlen(base);
	i = get_digits(nbr, len);
	ft_ultoa_base_rec(nbr, base, len);
	return (i);
}
