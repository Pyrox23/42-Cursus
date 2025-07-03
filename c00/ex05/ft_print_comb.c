/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:20:02 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/12 19:41:44 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void);

void	print_number(char d1, char d2, char d3)
{
	char		comma;
	char		space;

	comma = ',';
	space = ' ';
	write(1, &d1, 1);
	write(1, &d2, 1);
	write(1, &d3, 1);
	if (!(d1 == '7' && d2 == '8' && d3 == '9'))
	{
		write(1, &comma, 1);
		write(1, &space, 1);
	}
	return ;
}

void	ft_print_comb(void)
{
	char		digit1;
	char		digit2;
	char		digit3;

	digit1 = '0';
	digit2 = digit1 + 1;
	digit3 = digit2 + 1;
	while (digit1 <= '7')
	{
		while (digit2 <= '8')
		{
			while (digit3 <= '9')
			{
				print_number(digit1, digit2, digit3);
				digit3 = digit3 + 1;
			}
			digit2 = digit2 + 1;
			digit3 = digit2 + 1;
		}
		digit1 = digit1 + 1;
		digit2 = digit1 + 1;
		digit3 = digit2 + 1;
	}
	return ;
}
