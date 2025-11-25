/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:26:38 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/25 14:54:53 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error(void)
{
	write(2, "Available fractals: mandelbrot & julia\n", 39);
	write(2, "mandelbrot: ./fractol <Frac>\n", 29);
	write(2, "julia: ./fractol <Frac> <cx> <cy>; cx/y are optional\n", 53);
}

int	main(int ac, char **av)
{
	t_frac	*data;

	if (ac < 2 || ac == 3 || ac > 4)
		return (print_error(), 1);
	data = (t_frac *) malloc(1 * sizeof(t_frac));
	if (!data)
		return (perror("malloc"), 1);
	data->fract = av[1];
	data->fract_len = ft_strlen(data->fract);
	if (init_struct(data, check_c_val(data, av, ac)))
	{
		mlx_key_hook(data->window, key_reader, data);
		mlx_mouse_hook(data->window, mouse_reader, data);
		mlx_hook(data->window, 17, 0, end_program, data);
		make_fractal(data);
		mlx_loop(data->mlx);
	}
	else
	{
		write(2, "Error creating struct\n", 22);
		end_program(data);
	}
	return (0);
}
