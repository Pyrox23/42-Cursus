/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:26:38 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/29 01:08:01 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	print_error(void)
{
	write(2, "Available: mandelbrot, julia, celtic & celtic-julia\n", 52);
	write(2, "mandelbrot: ./fractol mandelbrot\n", 33);
	write(2, "julia: ./fractol julia <cx> <cy>; cx/y are optional\n", 53);
	write(2, "celtic: Just like a mandelbrot input\n", 37);
	write(2, "celtic-julia: Just like a julia input\n", 38);
}

int	main(int ac, char **av)
{
	t_frac	data;

	if (ac < 2 || ac == 3 || ac > 4)
		return (print_error(), 1);
	data.fract = av[1];
	init_struct(&data);
	if ((data.fract_len == 10 || data.fract_len == 6)
		&& (!ft_strncmp(data.fract, "mandelbrot", 10)
			|| !ft_strncmp(data.fract, "celtic", 6)) && ac == 4)
		return (print_error(), 1);
	if (init_struct_mlx(&data, check_c_val(&data, av, ac)))
	{
		mlx_key_hook(data.window, key_reader, &data);
		mlx_mouse_hook(data.window, mouse_reader, &data);
		mlx_hook(data.window, 17, 0, end_program, &data);
		make_fractal(&data);
		mlx_loop(data.mlx);
	}
	else
	{
		print_error();
		end_program(&data);
	}
	return (0);
}
