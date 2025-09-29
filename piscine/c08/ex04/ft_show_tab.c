/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:35:09 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/25 16:27:37 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_show_tab(struct s_stock_str *par);

void	print_char(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		print_char('-');
		if (nb != -__INT_MAX__ - 1)
			nb = nb * -1;
		else
		{
			nb = nb + 1;
			nb = nb * -1;
			ft_putnbr(nb / 10);
			nb = 8;
		}
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	print_char(nb % 10 + '0');
	return ;
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;
	int		j;

	i = 0;
	while (par[i].str != 0)
	{
		j = 0;
		while (par[i].str[j] != 0)
			write(1, &par[i].str[j++], 1);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		j = 0;
		while (par[i].copy[j] != 0)
			write(1, &par[i].copy[j++], 1);
		write(1, "\n", 1);
		i++;
	}
	return ;
}
