/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:38:34 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/25 15:07:40 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_struct_mlx(t_frac *data)
{
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
	return (1);
}

int	init_struct(t_frac *data, int init_c)
{
	data->x = 0;
	data->y = 0;
	data->color = 0xFCBE11;
	data->zoom = 200;
	data->off_x = -2.28;
	data->off_y = -1.62;
	data->max_it = 128;
	data->mlx = NULL;
	data->window = NULL;
	data->image = NULL;
	if (init_c)
	{
		data->cx = -0.745429;
		data->cy = 0.05;
	}
	return (init_struct_mlx(data));
}

int	check_c_val(t_frac *data, char **av, int ac)
{
	int	i;
	int	err;

	if (ac == 2)
		return (1);
	i = 2;
	err = 0;
	while (i < ac && !err)
	{
		err = str_is_float(av[i]);
		printf("@check: err = %d, i = %d, nb = %s\n", err, i, av[i]);
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
