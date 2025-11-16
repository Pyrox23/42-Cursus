/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:34:42 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/14 19:43:55 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(int c)
{
	if (c == ' ' || (c <= 13 && c >= 9))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac != 2)
		return (write(1, "\n", 1), 0);
	i = 0;
	while (av[1][i] && is_space(av[1][i]))
		i++;
	j = i;
	while (av[1][j] && !is_space(av[1][j]))
		j++;
	write(1, av[1] + i, j - i);
	write(1, "\n", 1);
	return (0);
}
