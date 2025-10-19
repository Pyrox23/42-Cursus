/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:39:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/19 18:24:08 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_ull	ft_power(int base, int exp)
{
	int		i;
	t_ull	ans;

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

static int	get_digits(t_ull nb, int b)
{
	int	dgt;

	if (!nb)
		return (1);
	dgt = 0;
	while (dgt < 20 && !(ft_power(b, dgt) <= nb && ft_power(b, dgt + 1) > nb))
		dgt++;
	return (dgt + 1);
}

static void	ft_ultoa_base_rec(t_ull nb, char *base, t_ull length, char **s)
{
	if (nb > length - 1)
		ft_ultoa_base_rec(nb / length, base, length, s);
	*(*s)++ = base[nb % length];
}

char	*ft_ultoa_base(t_ull nbr, char *base)
{
	int			i;
	char		*s;
	char		*ptr;
	t_ull		len;

	if (!base)
		return (NULL);
	len = (t_ull) ft_strlen(base);
	i = get_digits(nbr, len);
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (NULL);
	ptr = s;
	ft_ultoa_base_rec(nbr, base, len, &ptr);
	return (s);
}
