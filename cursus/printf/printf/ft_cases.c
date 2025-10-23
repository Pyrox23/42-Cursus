/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:40:53 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/20 18:47:53 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	case_s(char *s)
{
	size_t	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

static size_t	case_p(t_ull ptr, int *fl)
{
	size_t	len;
	char	*s;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	s = ft_ultoa_base(ptr, "0123456789abcdef");
	if (!s)
		return (*fl = 1, 0);
	len = ft_strlen(s);
	write(1, "0x", 2);
	write(1, s, len);
	free(s);
	return (len + 2);
}

static size_t	case_di(int nb, int *fl)
{
	size_t	len;
	char	*s;

	s = ft_itoa(nb);
	if (!s)
		return (*fl = 1, 0);
	len = ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
}

static size_t	case_ux(t_ull nb, char *base, int *fl)
{
	size_t	len;
	char	*s;

	s = ft_ultoa_base(nb, base);
	if (!s)
		return (*fl = 1, 0);
	len = ft_strlen(s);
	write(1, s, len);
	free(s);
	return (len);
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
		*bw += case_p((t_ull) va_arg(ap, void *), &fl);
	else if (flag == 'd' || flag == 'i')
		*bw += case_di(va_arg(ap, int), &fl);
	else if (flag == 'u')
		*bw += case_ux(va_arg(ap, t_ui), "0123456789", &fl);
	else if (flag == 'x')
		*bw += case_ux(va_arg(ap, t_ui), "0123456789abcdef", &fl);
	else if (flag == 'X')
		*bw += case_ux(va_arg(ap, t_ui), "0123456789ABCDEF", &fl);
	else if (flag == '%')
		*bw += case_c('%');
	else
		fl = -1;
	return (fl);
}
