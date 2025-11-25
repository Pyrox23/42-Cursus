/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:33:57 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/25 23:29:02 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_val_mandelbrot(t_frac *data)
{
	int		i;
	int		stop;
	double	aux;

	i = -1;
	stop = 0;
	data->zx = 0.0;
	data->zy = 0.0;
	data->cx = (data->x / data->zoom) + data->off_x;
	data->cy = (data->y / data->zoom) + data->off_y;
	while (!stop && ++i < data->max_it)
	{
		aux = data->zx * data->zx - data->zy * data->zy + data->cx;
		data->zy = 2.0 * data->zx * data->zy + data->cy;
		data->zx = aux;
		if (data->zx * data->zx + data->zy * data->zy > 4.0)
			stop = 1;
	}
	if (!stop)
		put_pixel(data, 0x000000);
	else
		put_pixel(data, data->color * (i % 255));
}

void	get_val_julia(t_frac *data)
{
	int		i;
	int		stop;
	double	aux;

	i = -1;
	stop = 0;
	data->zx = (data->x / data->zoom) + data->off_x;
	data->zy = (data->y / data->zoom) + data->off_y;
	while (!stop && ++i < data->max_it)
	{
		aux = data->zx * data->zx - data->zy * data->zy + data->cx;
		data->zy = 2.0 * data->zx * data->zy + data->cy;
		data->zx = aux;
		if (data->zx * data->zx + data->zy * data->zy > 4.0)
			stop = 1;
	}
	if (i == data->max_it)
		put_pixel(data, 0x000000);
	else
		put_pixel(data, data->color * (i % 255));
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

void	make_fractal(t_frac *data)
{
	if (data->fract_len == 10 && !ft_strncmp(data->fract, "mandelbrot", 10))
		print_image(data, get_val_mandelbrot);
	else if (data->fract_len == 5 && !ft_strncmp(data->fract, "julia", 5))
		print_image(data, get_val_julia);
	else
	{
		print_error();
		end_program(data);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image, 0, 0);
}
