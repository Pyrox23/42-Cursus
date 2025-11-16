/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:07:27 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/14 21:18:49 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//made in 4 minutes LOL
int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;
	int	i;

	i = 0;
	nbr = 0;
	while (is_space(str[i]))
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
