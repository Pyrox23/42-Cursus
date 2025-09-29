/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:54:41 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/22 16:09:19 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	solve(int **m, int current);

int	ft_check_pairs(int a, int b)
{
	if ((a == 1 && (b == 4 || b == 3 || b == 2))
		|| (b == 1 && (a == 4 || a == 3 || a == 2)))
		return (1);
	else if ((a == 2 && (b == 3 || b == 2))
		|| (b == 2 && (a == 2 || a == 3)))
		return (1);
	else
		return (0);
}

int	ft_index_check(int **m)
{
	int	i;

	i = 1;
	while ((ft_check_pairs(m[i][0], m[i][5]) == 1)
	&& (ft_check_pairs(m[0][i], m[5][i]) == 1) && i < 5)
		i++;
	if (i < 5)
		return (0);
	return (1);
}

int	check_corners(int **m)
{
	if ((m[0][1] == 1 && m[1][0] != 1)
	|| (m[0][4] == 1 && m[1][5] != 1)
	|| (m[5][1] == 1 && m[4][0] != 1)
	|| (m[5][4] == 1 && m[4][5] != 1))
		return (0);
	else
		return (1);
}

int	rush(int **m)
{
	if (ft_index_check(m) == 1 && check_corners(m) == 1)
		return (solve(m, 4));
	else
		return (0);
}

void	free_memory(int **m)
{
	int	rows;

	rows = 0;
	while (rows < 5)
		free(m[rows++]);
	free(m);
	return ;
}
