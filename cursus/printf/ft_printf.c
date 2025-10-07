/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:20:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/07 20:28:50 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

// conversion();
// flags/precision(#+. );
// width(flags 0 y -);
// return to print at main func

static size_t	ft_power(int base, int exp)
{
	int		i;
	size_t	ans;

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

int	get_digits(size_t nbr, int base)
{
	int	dgt;

	dgt = 0;
	while (!(ft_power(base, dgt) <= nbr && ft_power(base, dgt + 1) > nbr))
		dgt++;
	return (dgt + 1);
}

void	ft_ultoa_base_rec(size_t nb, char *base, size_t length, char *s)
{
	if (nb > length - 1)
		ft_ultoa_base_rec(nb / length, base, length, s);
	while (*s)
		s++;
	*s = base[nb % length];
}

char	*ft_ultoa_base(size_t nbr, char *base)
{
	int		i;
	char	*s;

	if (!base)
		return (NULL);
	i = get_digits(nbr, 16);
	s = ft_calloc(i + 1, sizeof(char));
	if (!s)
		return (free(base), NULL);
	ft_ultoa_base_rec(nbr, base, ft_strlen(base), s);
	free(base);
	return (s);
}

int	ft_printf(char const *fmt, ...)
{
	va_list	ap;
	size_t	i;
	size_t	j;
	int		dc;
	char	*s;
	void	*p;
	size_t	pux;

	va_start(ap, fmt);
	i = 0;
	j = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			if (fmt[i] == 'c')
			{
				dc = (char) va_arg(ap, int);
				write(1, &dc, 1);
			}
			else if (fmt[i] == 's')
			{
				s = va_arg(ap, char *);
				write(1, s, ft_strlen(s));
				j += ft_strlen(s);
			}
			else if (fmt[i] == 'p')
			{
				p = va_arg(ap, void *);
				s = ft_ultoa_base((size_t) & p, ft_strdup("0123456789abcdef"));
				write(1, "0x", 2);
				write(1, s, ft_strlen(s));
				j += ft_strlen(s);
				free(s);
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
	return (va_end(ap), i + j); //mine returns +10 than original
}

int	main(void)
{
	int				x = -42;
	char			*str = "hola buenos dias me presento.";
	char			c = 'a';
	unsigned int	uns = 4294967290;
	unsigned int	retft;
	unsigned int	ret;

	retft = ft_printf("ptr: %p\nstr: %s\nint: %d\nchar: %c\nhex: %x\nhex cap: %X\nunsigned int: %u\n", (void *) &x, str, x, c, uns, uns, uns);
	ret = printf("\nptr: %p\nstr: %s\nint: %d\nchar: %c\nhex: %x\nhex cap: %X\nunsigned int: %u\n", (void *) &x, str, x, c, uns, uns, uns);
	ft_printf("mine= %u\noriginal= %u\n", retft, ret);
	return (0);
}
