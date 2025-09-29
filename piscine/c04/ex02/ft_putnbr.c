/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:36:16 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/12 22:06:21 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb);

void	print_char(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		print_char('-');
		if (nb != -__INT_MAX__ - 1)
			nb = nb * -1;
		else
		{
			nb = nb + 1;
			nb = nb * -1;
			ft_putnbr(nb / 10);
			nb = 8;
		}
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	print_char(nb % 10 + '0');
	return ;
}
