/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 20:47:02 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/14 20:50:12 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	c;

	if (ac != 2)
		return (write(1, "\n", 1), 0);
	i = -1;
	while (av[1][++i])
	{
		c = av[1][i];
		if (av[1][i] <= 'z' && av[1][i] >= 'a')
			c = 'z' - (av[1][i] - 'a');
		else if (av[1][i] <= 'Z' && av[1][i] >= 'A')
			c = 'Z' - (av[1][i] - 'A');
		write(1, &c, 1);
	}
	write(1, "\n", 1);
	return (0);
}
