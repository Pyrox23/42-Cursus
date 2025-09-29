/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivgomez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 09:41:55 by ivgomez-          #+#    #+#             */
/*   Updated: 2025/06/22 19:16:51 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	format(int **m, int col, int nbr, int change_nbr);
int		check_rows(int **m, int col, int nbr);
int		mid_check_down(int **m, int col, int nbr);
int		mid_check_up(int **m, int col, int nbr);

int	check_solution(int **m)
{
	int	rw;
	int	cl;
	int	mv;

	rw = 1;
	while (rw < 5 && mv != -1)
	{
		cl = 1;
		while (cl < 5 && mv != -1)
		{
			mv = 1;
			while ((rw + mv) < 5 && mv != -1)
			{
				if (m[rw][cl] == m[rw + mv][cl] || m[cl][rw] == m[cl][rw + mv]
					|| m[rw][cl] <= 0 || m[rw + mv][cl] <= 0)
					mv = -2;
				mv++;
			}
			cl++;
		}
		rw++;
	}
	if (mv == -1)
		return (0);
	return (1);
}

int	check_condition(int **m, int col, int nbr)
{
	int		row;
	int		found;

	row = 1;
	found = 0;
	while (row < 5 && found == 0)
	{
		if (m[row][col] == -nbr)
		{
			m[row][col] *= -1;
			found = mid_check_down(m, col, nbr);
			found += mid_check_up(m, col, nbr);
			if (found == 0 || found == 2)
				m[row][col] *= -1;
		}
		row++;
	}
	if (found == 0 || found == 2)
		found = check_rows(m, col, nbr);
	if (found == 1)
		format(m, col, nbr, -1);
	return (found);
}

int	mid_check_down(int **m, int col, int nbr)
{
	int	max;
	int	count;
	int	row;
	int	nbr_used;

	row = 1;
	max = -4;
	count = 0;
	nbr_used = 0;
	while (row < 5 && max != 4)
	{
		if (m[row][col] == nbr)
			nbr_used = 1;
		if (m[row][col] > max && m[row][col] >= -4)
		{
			count++;
			max = m[row][col];
		}
		row++;
	}
	if (count == m[0][col] && nbr_used == 1)
		return (1);
	return (0);
}

int	mid_check_up(int **m, int col, int nbr)
{
	int	max;
	int	count;
	int	row;
	int	nbr_used;

	row = 4;
	max = -4;
	count = 0;
	nbr_used = 0;
	while (row > 0 && max != 4)
	{
		if (m[row][col] == nbr)
			nbr_used = 1;
		if (m[row][col] > max && m[row][col] >= -4)
		{
			count++;
			max = m[row][col];
		}
		row--;
	}
	if (count == m[5][col])
		return (1);
	return (0);
}

int	check_rows(int **m, int col, int nbr)
{
	int	row;
	int	col_local;
	int	found;

	row = 1;
	found = 0;
	while (row < 5 && found != 1)
	{
		col_local = 1;
		if (m[row][col] == -nbr)
		{
			found = 1;
			while (col_local < 5 && found == 1)
			{
				if ((m[row][col_local] == -nbr
					|| m[row][col_local] == nbr) && col_local != col)
					found = 0;
				col_local++;
			}
			if (col_local == 5 && found == 1)
				m[row][col] *= -1;
		}
		row++;
	}
	return (found);
}
