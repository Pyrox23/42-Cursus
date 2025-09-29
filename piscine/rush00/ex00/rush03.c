/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:48:32 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/15 15:58:44 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	print_line(int col, int row, int x, int y)
{
	if (row == 0 || row == y - 1)
		ft_putchar('A');
	else
		ft_putchar('B');
	while (col < x)
	{
		if (row == 0 || row == y - 1)
		{
			if (col == x - 1)
				ft_putchar('C');
			else
				ft_putchar('B');
		}
		else
		{
			if (col == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		col++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	long		cols;
	long		rows;

	cols = (long) x;
	rows = (long) y;
	if (cols < 0 || rows < 0 || cols > __INT_MAX__ || rows > __INT_MAX__)
		write(1, "ERROR, ENTRY NOT VALID\n", 23);
	else
		rows = 0;
	{
		while (rows < y && x > 0)
		{
			print_line(1, rows, x, y);
			rows++;
		}
	}
}
