/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:58:29 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/13 18:55:23 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void);

void	print_char(char c)
{
	write(1, &c, 1);
	return ;
}

void	print_number(int num)
{
	char		digit;

	digit = '0' + num / 10;
	print_char(digit);
	digit = '0' + num % 10;
	print_char(digit);
	return ;
}

void	ft_print_comb2(void)
{
	int		num1;
	int		num2;

	num1 = 0;
	num2 = 1;
	while (num1 < 99)
	{
		while (num2 < 100)
		{
			print_number(num1);
			print_char(' ');
			print_number(num2);
			if (!(num1 == 98 && num2 == 99))
			{
				print_char(',');
				print_char(' ');
			}
			num2 = num2 + 1;
		}
		num1 = num1 + 1;
		num2 = num1 + 1;
	}
	return ;
}
