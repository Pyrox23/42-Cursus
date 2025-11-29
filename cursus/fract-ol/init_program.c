/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:38:34 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/29 03:17:19 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_struct_mlx(t_frac *data, int init_c)
{
	if (init_c == 1)
		return (0);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!data->window)
		return (0);
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
		return (0);
	data->image_ptr = mlx_get_data_addr(data->image, &data->bpp,
			&data->s_line, &data->endian);
	if (init_c)
	{
		data->cx = -0.835;
		data->cy = -0.2321;
	}
	return (1);
}

void	init_struct(t_frac *data)
{
	data->x = 0;
	data->y = 0;
	data->color = 0x4B0082;
	data->zoom = 200;
	data->off_x = -2.28;
	data->off_y = -1.62;
	data->max_it = 128;
	data->mlx = NULL;
	data->window = NULL;
	data->image = NULL;
	data->fract_len = ft_strlen(data->fract);
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
		err = !((str[i] >= '0' && str[i] <= '9') || str[i] == '.');
		if (str[i] != '.')
			i++;
	}
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

int	check_c_val(t_frac *data, char **av, int ac)
{
	int	i;
	int	err;

	if (ac == 2)
		return (2);
	i = 2;
	err = 0;
	while (i < ac && !err)
	{
		av[i] = trim(av[i]);
		err = str_is_float(av[i]);
		if (!err)
		{
			if (i == 2)
				data->cx = ft_atof(av[i]);
			else
				data->cy = ft_atof(av[i]);
		}
		i++;
	}
	return (err);
}

void	print_image(t_frac *data, void (*f)(t_frac *))
{
	data->x = 0;
	while (data->x < WIDTH)
	{
		data->y = 0;
		while (data->y < HEIGHT)
		{
			f(data);
			data->y++;
		}
		data->x++;
	}
}
