/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:38:11 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/29 02:52:44 by ramo-cou         ###   ########.fr       */
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
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
		nbr = nbr * 10.0 + (str[i++] - '0');
	if (str[i] && str[i] != '.')
		return (nbr * sign);
	j = i + 1;
	while (str[j] && str[j] <= '9' && str[j] >= '0')
	{
		nbr = nbr + (str[j] - '0') / pow(10.0, j - i);
		j++;
	}
	return (nbr * sign);
}

int	ft_strncmp(const char *str, const char *s2, size_t n)
{
	int				comp;
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!n)
		return (0);
	comp = 0;
	i = 0;
	str1 = (unsigned char *) str;
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
	while (str[start] && str[start] == ' ')
		start++;
	end = start;
	while (str[end])
		end++;
	if (start == end)
		return (&str[start]);
	end--;
	while (start != end && str[end] == ' ')
		end--;
	str[end + 1] = 0;
	return (&str[start]);
}

void	put_pixel(t_frac *data, int color)
{
	int	aux;

	aux = (data->y * data->s_line) + (data->x * (data->bpp / 8));
	*(unsigned *)(data->image_ptr + aux) = color;
}

int	change_color(void)
{
	static int	list[10] = {0x4B0082, 0xFCBE11, 11894492, 0x0047FF, 0x9966CC,
		0x9A0EEA, 0x00CED1, 0xFF4500, 0x2F4F4F, 0x191970};
	static int	color = 1;

	if (color > 9)
		color = 0;
	return (list[color++]);
}
