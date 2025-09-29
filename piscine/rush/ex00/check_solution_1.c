/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivgomez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 09:41:55 by ivgomez-          #+#    #+#             */
/*   Updated: 2025/06/22 15:15:22 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_solution(int **sol)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < 5 && k != -1)
	{
		j = 1;
		while (j < 5 && k != -1)
		{
			k = 1;
			while ((i + k) < 5 && k != -1)
			{
				if (sol[i][j] == sol[i + k][j] || sol[j][i] == sol[j][i + k]
				|| sol[i][j] <= 0 || sol[i + k][j] <= 0)
					k = -2;
				k++;
			}
			j++;
		}
		i++;
	}
	if (k == -1)
		return (0);
	return (1);
}

int	check_left(int *row, int n)
{
	int	max;
	int	count;
	int	i;

	i = 0;
	max = 0;
	count = 0;
	while (i < 5)
	{
		if (row[i] > max)
		{
			count++;
			max = row[i];
		}
		i++;
	}
	if (count == n)
		return (1);
	return (1);
}

int	check_right(int *row, int n)
{
	int	max;
	int	count;
	int	i;

	i = 4;
	max = 0;
	count = 0;
	while (i > 0)
	{
		if (row[i] > max)
		{
			count++;
			max = row[i];
		}
		i--;
	}
	if (count == n)
		return (1);
	return (1);
}

int	check_up(int **m, int col, int n)
{
	int	max;
	int	count;
	int	i;

	i = 0;
	max = 0;
	count = 0;
	while (i < 5)
	{
		if (m[i][col] > max && m[i][col] > 0)
		{
			count++;
			max = m[i][col];
		}
		i++;
	}
	if (count == n)
		return (1);
	return (1);
}

int	check_down(int **m, int col, int n)
{
	int	max;
	int	count;
	int	i;

	i = 4;
	max = 0;
	count = 0;
	while (i > 0)
	{
		if (m[i][col] > max && m[i][col] > 0)
		{
			count++;
			max = m[i][col];
		}
		i--;
	}
	if (count == n)
		return (1);
	return (1);
}
