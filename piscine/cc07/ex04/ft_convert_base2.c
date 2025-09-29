/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:37:35 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/24 12:59:37 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len] != 0)
		len++;
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
	length = ft_strlen(base);
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
