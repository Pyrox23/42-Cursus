/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:25:08 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/22 15:54:27 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_condition(int **m, int col, int nbr);
void	cases_four(int **m, int pos_alt);
void	cases_three(int **m, int pos_alt);
void	cases_two(int **m, int pos_alt);
void	fill_one(int **m);

void	pair_cases(int **m, int pos_alt, int nbr)
{
	if (nbr == 2)
		cases_two(m, pos_alt);
	else if (nbr == 3)
		cases_three(m, pos_alt);
	else if (nbr == 4)
		cases_four(m, pos_alt);
	return ;
}

void	compare_cols(int **m, int col, int nbr)
{
	int		row;
	int		count_negative;
	int		save_pos;

	count_negative = 0;
	row = 1;
	while (row < 5 && count_negative != -1)
	{
		if (m[row][col] == nbr)
			count_negative = -1;
		else if (m[row][col] == nbr * -1)
		{
			save_pos = row;
			count_negative++;
		}
		row++;
	}
	if (count_negative == 1)
		format(m, col, nbr, save_pos);
	else if (count_negative > 1)
		check_condition(m, col, nbr);
	return ;
}

void	format(int **m, int col, int nbr, int change_nbr)
{
	int		row;

	row = 1;
	while (row < 5)
	{
		if (row == change_nbr)
			m[row][col] *= -1;
		else if (m[row][col] == nbr * -1)
			m[row][col] = 0;
		row++;
	}
	return ;
}

void	put_number(int **m, int nbr, int pos, int compare)
{
	int		pos_alt;

	pos_alt = 1;
	while (pos_alt < 5)
	{
		if (compare == 0)
			pair_cases(m, pos_alt, nbr);
		else
			compare_cols(m, pos_alt, nbr);
		pos_alt++;
	}
	return ;
}

int	solve(int **m, int current)
{
	int		pos;
	int		checks;

	pos = 1;
	checks = 0;
	if (current == 1)
	{
		fill_one(m);
		return (check_solution(m));
	}
	while (checks < 3)
	{
		while (pos < 5)
			put_number(m, current, pos++, checks);
		pos = 1;
		checks++;
	}
	if (check_solution(m) == 1)
		return (solve(m, current - 1));
	return (0);
}
