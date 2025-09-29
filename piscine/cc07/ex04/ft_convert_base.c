/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 18:59:27 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/24 12:55:13 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_atoi_base(char *str, char *base);
int		ft_strlen(char *str);

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
	if (exit == 1 || len <= 1)
		return (0);
	return (len);
}

char	*ft_strcat_char(char *dest, char c)
{
	int		dest_len;

	dest_len = ft_strlen(dest);
	dest[dest_len] = c;
	dest[dest_len + 1] = 0;
	return (dest);
}

void	ft_putnbr_base_rec(long nb, char *base, int length, char *str)
{
	if (nb < 0)
	{
		ft_strcat_char(str, '-');
		nb = nb * -1;
	}
	if (nb > length - 1)
		ft_putnbr_base_rec(nb / length, base, length, str);
	ft_strcat_char(str, base[nb % length]);
	return ;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*str;
	int			len;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	str = (char *) malloc(sizeof(char) * 34);
	len = ft_strlen(base_to);
	ft_putnbr_base_rec((long) ft_atoi_base(nbr, base_from), base_to, len, str);
	return (str);
}
