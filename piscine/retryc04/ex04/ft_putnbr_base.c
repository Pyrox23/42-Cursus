/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:48:43 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/18 17:46:43 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_char(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putnbr_base_rec(long nb, char *base, int length)
{
	if (nb < 0)
	{
		print_char('-');
		nb = nb * -1;
	}
	if (nb > length - 1)
		ft_putnbr_base_rec(nb / length, base, length);
	print_char(base[nb % length]);
	return ;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		exit;
	int		j;
	long	lnbr;

	i = 0;
	exit = 0;
	while (base[i] != 0 && exit != 1)
	{
		j = i + 1;
		if (base[i] == '-' || base[i] == '+')
			exit = 1;
		while (base[j] != 0 && exit != 1)
		{
			if (base[i] == base[j])
				exit = 1;
			j++;
		}
		i++;
	}
	if (i > 1 && exit != 1)
	{
		lnbr = (long) nbr;
		ft_putnbr_base_rec(lnbr, base, i);
	}
}
