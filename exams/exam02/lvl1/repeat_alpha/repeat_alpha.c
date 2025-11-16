/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 20:12:58 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/14 20:26:08 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	j;
	int	i;

	if (ac != 2)
		return (write(1, "\n", 1), 0);
	i = -1;
	while (av[1][++i])
	{
		j = 1;
		if (av[1][i] <= 'z' && av[1][i] >= 'a')
			j += av[1][i] - 'a';
		else if (av[1][i] <= 'Z' && av[1][i] >= 'A')
			j += av[1][i] - 'A';
		while (j--)
			write(1, av[1] + i, 1);
	}
	write(1, "\n", 1);
	return (0);
}
