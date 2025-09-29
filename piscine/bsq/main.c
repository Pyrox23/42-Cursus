/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusanche <gusanche@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:50:23 by gusanche          #+#    #+#             */
/*   Updated: 2025/07/02 18:31:00 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "structs.h"

int	check_map(char *map);

void	free_struct(struct s_map *map_ptr)
{
	int	i;

	i = 0;
	map_ptr->mtx--;
	while (map_ptr->mtx[i])
		free(map_ptr->mtx[i++]);
	free(map_ptr->mtx);
}

unsigned long long	get_size(int file)
{
	unsigned long long		size;
	char					buffer[100];
	int						checking;

	size = 0;
	checking = 1;
	while (checking > 0)
	{
		checking = read(file, buffer, sizeof(buffer));
		size += checking;
	}
	return (size);
}

int	process_file(char *argv, char **buff)
{
	int		file;
	int		size;

	file = 0;
	if (argv)
		file = open(argv, O_RDONLY);
	else
		return (FALSE);
	size = get_size(file);
	close(file);
	if (size == -1)
		return (FALSE);
	file = open(argv, O_RDONLY);
	*buff = malloc(sizeof(char) * (size + 1));
	if (!*buff)
		return (FALSE);
	read(file, *buff, size);
	close(file);
	buff[0][size] = 0;
	return (TRUE);
}

struct s_map	struct_obj(char **mtx)
{
	t_map			obj;
	unsigned int	size;

	size = 0;
	while (mtx[0][size] && mtx[0][size] <= '9' && mtx[0][size] >= '0'
		&& mtx[0][size + 3] != '\n')
		size++;
	obj.empty = mtx[0][size++];
	obj.obs = mtx[0][size++];
	obj.fill = mtx[0][size++];
	obj.mtx = ++mtx;
	size = 0;
	while (mtx[size])
		size++;
	obj.height = size;
	size = 0;
	while (mtx[0][size] && mtx[0][size] != '\n')
		size++;
	obj.width = size;
	return (obj);
}

int	main(int args, char *argv[])
{
	char	*buff;
	int		i;

	buff = NULL;
	i = 1;
	if (args < 2)
	{
		buff = open_standard();
		args++;
	}
	while (i < args)
	{
		if (buff)
			try_map_input(buff, NULL);
		else
			try_map_input(buff, argv[i]);
		if (i + 1 != args)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
