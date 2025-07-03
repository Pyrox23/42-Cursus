/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 13:00:58 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/22 14:03:26 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_22_for_two(int **m, int pos_alt)
{
	int		pos_four;
	int		pos_three;

	pos_four = get_nbr(m, pos_alt, 4);
	pos_three = get_nbr(m, pos_alt, 3);
	if (pos_four == 2 && pos_three == 1)
		m[pos_alt][4] = 2;
	else if (pos_four == 3 && pos_three == 4)
		m[pos_alt][1] = 2;
	else if (pos_four == 2)
	{
		m[pos_alt][1] = -2;
		m[pos_alt][3] = -2;
	}
	else
	{
		m[pos_alt][1] = -2;
		m[pos_alt][1] = -2;
	}
	return ;
}

int	get_nbr(int **m, int row, int find)
{
	int		col;

	col = 1;
	while (col < 5 && m[row][col] != find)
		col++;
	return (col);
}

void	fill_one(int **m)
{
	int		row;
	int		col;

	row = 1;
	col = 1;
	while (row < 5)
	{
		while (col < 5)
		{
			if (m[row][col] <= 0)
				m[row][col] = 1;
			col++;
		}
		col = 1;
		row++;
	}
	return ;
}
