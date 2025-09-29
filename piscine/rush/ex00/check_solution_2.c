/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 15:17:34 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/22 15:59:02 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	format(int **m, int col, int nbr, int change_nbr);
int		check_rows(int **m, int col, int nbr);

int	check_solution(int **m, int col, int nbr)
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
			found = check_down(m, col, nbr);
			if (found == 0)
				found = check_up(m, col, nbr);
			if (found == 0)
				m[row][col] *= -1;
		}
		row++;
	}
	if (found == 0)
		found = check_rows(m, col, nbr);
	if (found == 1)
		format(m, col, nbr, -1);
	return (found);
}

int	check_down(int **m, int col, int n)
{
	int	max;
	int	count;
	int	row;

	row = 1;
	max = 0;
	count = 0;
	while (row < 5 && max != 4)
	{
		if (m[row][col] > max && m[row][col] > 0)
		{
			count++;
			max = m[i][col];
		}
		row++;
	}
	if (count == m[0][col])
		return (1);
	return (0);
}

int	check_up(int **m, int col, int n)
{
	int	max;
	int	count;
	int	row;

	row = 5;
	max = 0;
	count = 0;
	while (row > 0 && max != 4)
	{
		if (m[row][col] > max && m[row][col] > 0)
		{
			count++;
			max = m[i][col];
		}
		row--;
	}
	if (count == m[5][col])
		return (1);
	return (0);
}
