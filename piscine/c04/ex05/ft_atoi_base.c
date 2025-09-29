/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:00:52 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/23 19:19:52 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);

int	check_base(char *base)
{
	int		len;
	int		j;
	int		exit;

	len = 0;
	exit = 0;
	while (base[len] != 0 && exit != 1)
	{
		j = len + 1;
		if (base[len] == '-' || base[len] == '+')
			exit = 1;
		while (base[j] != 0 && exit != 1)
		{
			if (base[len] == base[j])
				exit = 1;
			j++;
		}
		len++;
	}
	if (exit == 1)
		return (0);
	return (len);
}

int	is_in_base(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != 0 && base[i] != c)
		i++;
	if (base[i] == 0)
		return (0);
	return (1);
}

int	atoi_rec(char *str, char *base, int length, int digit)
{
	int	nbr;
	int	i;

	if (digit == 0)
		return (0);
	i = 0;
	nbr = 0;
	while (base[nbr] != *str)
		nbr++;
	while (i < digit - 1)
	{
		nbr *= length;
		i++;
	}
	return (nbr + atoi_rec(++str, base, length, --digit));
}

int	ft_atoi_base(char *str, char *base)
{
	int		digits;
	int		nbr;
	int		sign;
	int		length;

	digits = 0;
	sign = 0;
	nbr = 0;
	length = check_base(base);
	if (length == 0)
		return (0);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (is_in_base(str[digits], base) == 1)
		digits++;
	nbr = atoi_rec(str, base, length, digits);
	if (sign % 2 != 0)
		nbr = nbr * -1;
	return (nbr);
}
