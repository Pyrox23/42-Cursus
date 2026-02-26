/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 22:43:21 by ramo-cou          #+#    #+#             */
/*   Updated: 2026/02/08 22:24:48 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_nbr(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		if (n == -__INT_MAX__ - 1)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
		print_nbr(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

size_t	get_str_len(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	compare_strings(const char *s1, const char *s2, size_t n)
{
	int				comp;
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!n)
		return (0);
	comp = 0;
	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (str1[i] && str2[i] && !comp && i < n)
	{
		comp = str1[i] - str2[i];
		i++;
	}
	if (!comp && i < n)
		comp = str1[i] - str2[i];
	return (comp);
}

char	*trim(char *str)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!str)
		return (str);
	while (str[start] && (str[start] == ' ' || str[start] == '\t'))
		start++;
	end = start;
	while (str[end])
		end++;
	if (start == end)
		return (&str[start]);
	end--;
	while (start != end && (str[end] == ' ' || str[end] == '\t'))
		end--;
	str[end + 1] = 0;
	return (&str[start]);
}

int	ft_atol(const char *str)
{
	int		sign;
	long	nbr;
	int		i;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] <= '9' && str[i] >= '0')
		nbr = nbr * 10 + (str[i++] - '0');
	return (nbr * sign);
}
