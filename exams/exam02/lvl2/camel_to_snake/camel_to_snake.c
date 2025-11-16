/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 20:52:02 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/14 20:57:14 by ramo-cou         ###   ########.fr       */
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
		if (!i)
			write(1, av[1], 1);
		else
		{
			if (av[1][i] <= 'Z' && av[1][i] >= 'A')
			{
				write(1, "_", 1);
				c = av[1][i] + 32;
			}
			write(1, &c, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
