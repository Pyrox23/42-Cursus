/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:35:44 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/07/02 17:12:13 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	is_key(char c, char *keys)
{
	int	exit;
	int	i;

	exit = 0;
	i = 0;
	while (keys[i] && i < 2 && !exit)
	{
		if (keys[i] == c)
			exit = 1;
		i++;
	}
	return (exit);
}

unsigned long	get_line_length(char *map)
{
	unsigned long	length;

	length = 0;
	while (map[length] && map[length] != '\n')
		length++;
	return (length);
}

int	is_valid(char *map, char *keys, unsigned long size)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	length;

	i = 0;
	j = 0;
	length = 0;
	while (i < size && j == length)
	{
		j = 0;
		if (length == 0)
			length = get_line_length(map);
		while (*map && is_key(*map, keys))
		{
			j++;
			map++;
		}
		i++;
		if (*map == '\n')
			map++;
	}
	if (!size || !length || i != size || j != length)
		return (0);
	return (*(map - 1) == '\n' && *map == 0);
}

int	is_valid_keys(char *keys)
{
	int	i;
	int	valid;
	int	j;

	i = 0;
	valid = 1;
	while (keys[i] != '\n' && valid)
	{
		j = i + 1;
		while (keys[j] != '\n' && valid)
			if (keys[i] == keys[j++])
				valid = 0;
		i++;
	}
	return (i == 3 && valid);
}

int	check_map(char *map)
{
	unsigned long	size;
	char			*keys;

	size = 0;
	keys = (char *) 0;
	if (!map || !*map)
		return (0);
	while (map[size] && map[size] <= '9' && map[size] >= '0'
		&& map[size + 3] != '\n')
		size++;
	if (size == 0)
		return (0);
	keys = map + size;
	size = get_nbr(map, size);
	while (*map != '\n')
		map++;
	if (is_valid_keys(keys))
		return (is_valid(++map, keys, size));
	return (0);
}
