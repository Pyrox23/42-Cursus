/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 12:52:45 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/22 16:57:36 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int		rush(int **m);
void	free_memory(int **m);

void	print_solution(int **m)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	j = 1;
	while (i < 5)
	{
		while (j < 5)
		{
			c = m[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 1;
	}
	return ;
}

int	check_chars(char *str)
{
	int		len;
	int		err;

	len = 0;
	err = 0;
	while (*str != 0 && err != 1)
	{
		err = 1;
		if (len % 2 == 0 && *str >= '0' && *str <= '9')
			err = 0;
		else if (*str == 32)
			err = 0;
		len++;
		str++;
	}
	if (len == 31 && err == 1)
		len = 0;
	return (len);
}

void	create_matrix(int **m, char *str)
{
	int		row;
	int		col;
	int		change;

	row = 0;
	col = 1;
	change = 0;
	while (change < 4)
	{
		while (col <= 4)
		{
			if (change < 2)
				m[row][col] = *str - '0';
			else
				m[col][row] = *str - '0';
			str += 2;
			col++;
		}
		change++;
		col = 1;
		if (change % 2 != 0)
			row += 5;
		else
			row = 0;
	}
}

int	**alloc_mem(void)
{
	int		i;
	int		**m;

	i = 0;
	m = (int **) malloc(8 * 6);
	while (i < 6)
	{
		m[i] = (int *) malloc(4 * 6);
		i++;
	}
	return (m);
}

int	main(int argc, char *argv[])
{
	int		**m;
	int		sol;

	sol = 0;
	if (argc == 2)
	{
		if (check_chars(argv[1]) != 31)
			write(1, "Error\n", 6);
		else
		{
			m = alloc_mem();
			create_matrix(m, argv[1]);
			sol = rush(m);
			if (sol == 1)
				print_solution(m);
			else
				write(1, "Error\n", 6);
			free_memory(m);
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
