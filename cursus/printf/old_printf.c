/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:20:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/12 18:34:09 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// conversion();
// flags/precision(#+. );
// width(flags 0 y -);
// return to print at main func

static t_ull	ft_power(int base, int exp)
{
	int		i;
	t_ull	ans;

	if (!exp)
		return (1);
	if (!base || exp < 0)
		return (0);
	i = 0;
	ans = 1;
	while (i++ < exp)
		ans *= base;
	return (ans);
}

static int	get_digits(t_ull nb, int b)
{
	int	dgt;

	if (!nb)
		return (1);
	dgt = 0;
	while (dgt < 20 && !(ft_power(b, dgt) <= nb && ft_power(b, dgt + 1) > nb))
		dgt++;
	return (dgt + 1);
}

static void	ft_ultoa_base_rec(t_ull nb, char *base, t_ull length, char *s)
{
	if (nb > length - 1)
		ft_ultoa_base_rec(nb / length, base, length, s);
	while (*s)
		s++;
	*s = base[nb % length];
}

static char	*ft_ultoa_base(t_ull nbr, char *base)
{
	int			i;
	char		*s;
	t_ull		len;

	if (!base)
		return (NULL);
	len = (t_ull) ft_strlen(base);
	i = get_digits(nbr, len);
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (free(base), NULL);
	ft_ultoa_base_rec(nbr, base, len, s);
	free(base);
	return (s);
}

int	ft_printf(char const *fmt, ...)
{
	va_list	ap;
	size_t	i;
	size_t	j;
	size_t	count_perc;
	int		dc;
	char	*s;
	t_ull	pux;

	va_start(ap, fmt);
	i = 0;
	j = 0;
	count_perc = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			count_perc += 2;
			if (fmt[i] == 'c')
			{
				dc = (char) va_arg(ap, int);
				write(1, &dc, 1);
				j++;
			}
			else if (fmt[i] == 's')
			{
				s = va_arg(ap, char *);
				if (!s)
				{
					write(1, "(null)", 6);
					j += 6;
				}
				else
				{
					write(1, s, ft_strlen(s));
					j += ft_strlen(s);
				}
			}
			else if (fmt[i] == 'p')
			{
				pux = (t_ull) va_arg(ap, void *);
				if (pux)
				{
					s = ft_ultoa_base(pux, ft_strdup("0123456789abcdef"));
					write(1, "0x", 2);
					write(1, s, ft_strlen(s));
					j += ft_strlen(s) + 2;
					free(s);
				}
				else
				{
					write(1, "(nil)", 5);
					j += 5;
				}
			}
			else if (fmt[i] == 'd' || fmt[i] == 'i')
			{
				dc = va_arg(ap, int);
				s = ft_itoa(dc);
				write(1, s, ft_strlen(s));
				j += ft_strlen(s);
				free(s);
			}
			else if (fmt[i] == 'u')
			{
				pux = va_arg(ap, unsigned int);
				s = ft_ultoa_base(pux, ft_strdup("0123456789"));
				write(1, s, ft_strlen(s));
				j += ft_strlen(s);
				free(s);
			}
			else if (fmt[i] == 'x')
			{
				pux = va_arg(ap, unsigned int);
				s = ft_ultoa_base(pux, ft_strdup("0123456789abcdef"));
				write(1, s, ft_strlen(s));
				j += ft_strlen(s);
				free(s);
			}
			else if (fmt[i] == 'X')
			{
				pux = va_arg(ap, unsigned int);
				s = ft_ultoa_base(pux, ft_strdup("0123456789ABCDEF"));
				write(1, s, ft_strlen(s));
				j += ft_strlen(s);
				free(s);
			}
			else if (fmt[i] == '%')
			{
				write(1, "%%", 1);
				j++;
			}
			else
				return (va_end(ap), -1);
		}
		else
			write(1, fmt + i, 1);
		i++;
	}
	return (va_end(ap), i + j - count_perc);
}

size_t	case_c(char c)
{
	write(1, &dc, 1);
	return (1);
}
