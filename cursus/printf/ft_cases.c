/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:40:53 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/23 23:28:12 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		if (n == -__INT_MAX__ - 1)
			return (case_s("-2147483648"));
		count += case_c('-');
		n *= -1;
	}
	if (n > 9)
		count += print_nbr(n / 10);
	case_c(n % 10 + '0');
	return (count);
}

size_t	case_s(char *s)
{
	size_t	len;

	if (!s)
		return (case_s("(null)"));
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

size_t	case_p(size_t ptr)
{
	if (!ptr)
		return (case_s("(nil)"));
	return (case_s("0x") + ft_ultoa_base(ptr, HEX_LOW));
}

size_t	case_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	check_case(va_list ap, char flag, size_t *bw)
{
	int	fl;

	fl = 0;
	if (flag == 'c')
		*bw += case_c((char) va_arg(ap, int));
	else if (flag == 's')
		*bw += case_s(va_arg(ap, char *));
	else if (flag == 'p')
		*bw += case_p((size_t) va_arg(ap, void *));
	else if (flag == 'd' || flag == 'i')
		*bw += print_nbr(va_arg(ap, int));
	else if (flag == 'u')
		*bw += ft_ultoa_base(va_arg(ap, unsigned int), BASE_10);
	else if (flag == 'x')
		*bw += ft_ultoa_base(va_arg(ap, unsigned int), HEX_LOW);
	else if (flag == 'X')
		*bw += ft_ultoa_base(va_arg(ap, unsigned int), HEX_UP);
	else if (flag == '%')
		*bw += case_c('%');
	else
		fl = 1;
	return (fl);
}
