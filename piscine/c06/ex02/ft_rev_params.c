/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:46:41 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/19 18:49:32 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
	write(1, "\n", 1);
	return ;
}

int	main(int argc, char *argv[])
{
	argc--;
	while (argc > 0)
	{
		ft_putstr(argv[argc]);
		argc--;
	}
	return (0);
}
