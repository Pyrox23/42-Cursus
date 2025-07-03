/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:23:23 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/19 17:26:18 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str);

void	print_hex(char c)
{
	unsigned char		digit1;
	unsigned char		digit2;

	digit1 = (unsigned char) c / 16;
	digit2 = (unsigned char) c % 16;
	if (digit1 < 10)
		digit1 += '0';
	else
		digit1 += 'a' - 10;
	if (digit2 < 10)
		digit2 += '0';
	else
		digit2 += 'a' - 10;
	write(1, "\\", 1);
	write(1, &digit1, 1);
	write(1, &digit2, 1);
	return ;
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != 0)
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
			print_hex(*str);
		str++;
	}
	return ;
}
