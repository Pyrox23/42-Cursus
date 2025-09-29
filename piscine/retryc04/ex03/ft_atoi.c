/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:21:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/19 13:21:53 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str);

int	atoi_rec(char *str, int digit)
{
	int	nbr;
	int	i;

	if (digit == 0)
		return (0);
	i = 0;
	nbr = *str - '0';
	while (i < digit - 1)
	{
		nbr *= 10;
		i++;
	}
	return (nbr + atoi_rec(++str, --digit));
}

int	ft_atoi(char *str)
{
	int		digits;
	int		nbr;
	int		sign;

	digits = 0;
	sign = 0;
	nbr = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	while (str[digits] <= '9' && str[digits] >= '0')
		digits++;
	nbr = atoi_rec(str, digits);
	if (sign % 2 != 0)
		nbr = nbr * -1;
	return (nbr);
}
