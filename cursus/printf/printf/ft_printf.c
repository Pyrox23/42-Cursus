/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:20:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/20 19:08:57 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// conversion();
// flags/precision(#+. );
// width(flags 0 y -);
// return to print at main func

size_t	case_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	write_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(char const *fmt, ...)
{
	va_list	ap;
	size_t	i;
	size_t	bw;
	int		flag;

	va_start(ap, fmt);
	i = 0;
	bw = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			flag = check_case(ap, fmt[i], &bw);
			if (flag == 1)
				return (va_end(ap), -1);
			else if (flag == -1)
				bw += write_char(fmt[--i]);
		}
		else
			bw += write_char(fmt[i]);
		i++;
	}
	return (va_end(ap), bw);
}
