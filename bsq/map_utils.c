/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:14:24 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/07/02 17:04:11 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "structs.h"

unsigned long	get_nbr(char *map, unsigned long digit)
{
	unsigned long	nbr;
	unsigned long	i;

	if (digit == 0)
		return (0);
	i = 0;
	nbr = *map - '0';
	while (i < digit - 1)
	{
		nbr *= 10;
		i++;
	}
	return (nbr + get_nbr(++map, --digit));
}

void	print_mtx(struct s_map *obj)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < obj->height)
	{
		j = 0;
		while (j < obj->width)
		{
			write(1, &obj->mtx[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	try_input_as_name(char **buff)
{
	char	*input;

	input = NULL;
	process_file(*buff, &input);
	if (input)
	{
		free(*buff);
		*buff = input;
	}
	return ;
}

void	try_map_input(char *buff, char *name)
{
	t_map	obj;

	if (!buff)
		process_file(name, &buff);
	else
		try_input_as_name(&buff);
	if (buff && check_map(buff))
	{
		obj = struct_obj(ft_split(buff, "\n"));
		solve(&obj);
		print_mtx(&obj);
		free_struct(&obj);
	}
	else
		write(2, "map error\n", 10);
	if (buff)
		free(buff);
	return ;
}
