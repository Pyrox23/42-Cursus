/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:13:28 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/07/02 16:36:35 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "structs.h"
#include <stdlib.h>

int	calc_min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	if (b < c)
		return (b);
	return (c);
}

void	set_solution(t_map *map_ptr, struct s_square sqr)
{
	int	i;
	int	j;

	sqr.y = sqr.y - sqr.side + 1;
	sqr.x = sqr.x - sqr.side + 1;
	i = sqr.y;
	while (i < sqr.side + sqr.y)
	{
		j = sqr.x;
		while (j < sqr.side + sqr.x)
		{
			map_ptr->mtx[i][j] = map_ptr->fill;
			j++;
		}
		i++;
	}
}

int	**set_aux_mtx(t_map *map_ptr)
{
	int	**mtx;
	int	i;

	mtx = malloc(sizeof(int *) * map_ptr->height);
	if (!mtx)
		return ((void *)0);
	i = 0;
	while (i < map_ptr->height)
		mtx[i++] = NULL;
	i = 0;
	while (i < map_ptr->height)
	{
		mtx[i] = malloc(sizeof(int) * map_ptr->width);
		if (!mtx[i])
			return ((void *)0);
		i++;
	}
	return (mtx);
}

void	fill_aux(int i, t_map *map_ptr, int **aux_mtx, struct s_square *sqr)
{
	int	j;

	j = 0;
	while (j < map_ptr->width)
	{
		if (map_ptr->mtx[i][j] == map_ptr->obs)
			aux_mtx[i][j] = 0;
		else if (i == 0 || j == 0)
			aux_mtx[i][j] = 1;
		else
			aux_mtx[i][j] = calc_min(
					aux_mtx[i][j - 1],
					aux_mtx[i - 1][j],
					aux_mtx[i - 1][j - 1]) + 1;
		if (aux_mtx[i][j] > sqr->side)
		{
			sqr->side = aux_mtx[i][j];
			sqr->x = j;
			sqr->y = i;
		}
		j++;
	}
	return ;
}

int	solve(t_map *map_ptr)
{
	int				**aux_mtx;
	struct s_square	sqr;
	int				i;

	sqr.side = 0;
	aux_mtx = set_aux_mtx(map_ptr);
	i = 0;
	while (i < map_ptr->height)
	{
		fill_aux(i, map_ptr, aux_mtx, &sqr);
		i++;
	}
	i = 0;
	while (i < map_ptr->height)
		free(aux_mtx[i++]);
	free(aux_mtx);
	set_solution(map_ptr, sqr);
	return (sqr.side);
}
