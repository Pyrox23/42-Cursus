/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:20:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/23 23:37:39 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
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
			if (flag && fmt[i])
				bw += case_c(fmt[--i]);
			else if (flag)
				return (va_end(ap), -1);
		}
		else
			bw += case_c(fmt[i]);
		i++;
	}
	return (va_end(ap), bw);
}
