/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:20:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/12 19:43:09 by ramo-cou         ###   ########.fr       */
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

int	ft_printf(char const *fmt, ...)
{
	va_list	ap;
	size_t	i;
	size_t	bw;
	size_t	count_perc;

	va_start(ap, fmt);
	i = 0;
	bw = 0;
	count_perc = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			count_perc += 2;
			if (check_case(ap, fmt[i], &bw))
				return (va_end(ap), -1);
		}
		else
			write(1, fmt + i, 1);
		i++;
	}
	return (va_end(ap), i + bw - count_perc);
}
