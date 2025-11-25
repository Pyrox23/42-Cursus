/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:38:11 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/25 23:30:12 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *str)
{
	int		sign;
	double	nbr;
	int		i;
	int		j;

	i = 0;
	nbr = 0.0;
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
		nbr = nbr * 10.0 + (str[i++] - '0');
	if (str[i] && str[i] == '.')
		i++;
	j = i;
	while (str[j] && str[j] <= '9' && str[j] >= '0')
	{
		nbr = nbr + (str[j] - '0') / (10.0 * j);
		j++;
	}
	return (nbr * sign);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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

int	str_is_float(char *str)
{
	int	i;
	int	err;

	if (!*str)
		return (1);
	i = 0;
	err = 0;
	while (str[i] && str[i] != '.' && !err)
	{
		if ((str[i] == '-' || str[i] == '+') && i == 0 && str[i + 1])
			i++;
		err = !(str[i] >= '0' && str[i] <= '9');
		i++;
	}
	printf("@flt err = %d, c_stop = %c\n", err, str[i]);
	if (!err && str[i] == '.')
	{
		i++;
		while (str[i] && !err)
		{
			err = !(str[i] >= '0' && str[i] <= '9');
			i++;
		}
	}
	return (err);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	put_pixel(t_frac *data, int color)
{
	int	aux;

	aux = (data->y * data->s_line) + (data->x * (data->bpp / 8));
	*(unsigned *)(data->image_ptr + aux) = color;
}
