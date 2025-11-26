/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:41:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/26 20:41:33 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_frac *data, int x, int y, int move)
{
	double	zoom_fact;

	zoom_fact = 1.25;
	if (move == 4)
	{
		data->off_x = (x / data->zoom + data->off_x)
			- (x / (data->zoom * zoom_fact));
		data->off_y = (y / data->zoom + data->off_y)
			- (y / (data->zoom * zoom_fact));
		data->zoom *= zoom_fact;
	}
	else
	{
		data->off_x = (x / data->zoom + data->off_x)
			- (x / (data->zoom / zoom_fact));
		data->off_y = (y / data->zoom + data->off_y)
			- (y / (data->zoom / zoom_fact));
		data->zoom /= zoom_fact;
	}
	printf("Actual: zoom = %f, ox = %f, oy = %f\n", data->zoom, data->off_x, data->off_y);
}

int	key_reader(int k_code, t_frac *data)
{
	printf("Key! code = %d\n", k_code);
	if (k_code == ESC)
		end_program(data);
	else if (k_code == K_UP)
		data->off_y -= 5 / data->zoom;
	else if (k_code == K_DW)
		data->off_y += 5 / data->zoom;
	else if (k_code == K_LF)
		data->off_x -= 5 / data->zoom;
	else if (k_code == K_RG)
		data->off_x += 5 / data->zoom;
	else
		return (0);
	make_fractal(data);
	return (0);
}

int	mouse_reader(int m_code, int x, int y, t_frac *data)
{
	if (m_code == 4 || m_code == 5)
	{
		zoom(data, x, y, m_code);
		make_fractal(data);
	}
	return (0);
}

int	end_program(t_frac *data)
{
	int	ret;

	ret = !(data->mlx && data->window && data->image);
	if (data->mlx)
	{
		if (data->image)
			mlx_destroy_image(data->mlx, data->image);
		if (data->window)
			mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
	exit(ret);
	return (0);
}
