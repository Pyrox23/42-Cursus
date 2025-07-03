/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:39:36 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/13 21:58:00 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size);

void	ft_swap(int *a, int *b)
{
	int		aux;

	aux = *a;
	*a = *b;
	*b = aux;
	return ;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size / 2)
	{
		ft_swap(tab + i, tab + size - i - 1);
		i = i + 1;
	}
	return ;
}
