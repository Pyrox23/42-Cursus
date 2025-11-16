/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 20:59:32 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/14 21:06:17 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	ans;

	if (ac != 4)
		return (printf("\n"), 0);
	if (av[2][0] == '+')
		ans = atoi(av[1]) + atoi(av[3]);
	else if (av[2][0] == '-')
		ans = atoi(av[1]) - atoi(av[3]);
	else if (av[2][0] == '*')
		ans = atoi(av[1]) * atoi(av[3]);
	else if (av[2][0] == '/')
		ans = atoi(av[1]) / atoi(av[3]);
	else if (av[2][0] == '%')
		ans = atoi(av[1]) % atoi(av[3]);
	printf("%d\n", ans);
	return (0);
}
