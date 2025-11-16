/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:45:24 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/14 20:00:31 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	putnbr(int nbr)
{
	if (nbr < 0)
	{
		if (nbr == -__INT_MAX__ - 1)
		{
			putnbr(nbr / 10);
			nbr = 8;
		}
		else
		{
			nbr *= -1;
			ft_putchar('-');
		}
	}
	if (nbr > 9)
		putnbr(nbr / 10);
	ft_putchar('0' + nbr % 10);
}

int	main(void)
{
	int	i;
	int	print;

	i = 1;
	while (i <= 100)
	{
		print = 0;
		if (!(i % 3))
			print = write(1, "fizz", 4);
		if (!(i % 5))
			print = write(1, "buzz", 4);
		if (!print)
			putnbr(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
