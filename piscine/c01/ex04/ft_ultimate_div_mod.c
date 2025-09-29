/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft_mod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:59:59 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/13 21:07:44 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		aux0;
	int		aux1;

	aux0 = *a;
	aux1 = *b;
	*a = aux0 / aux1;
	*b = aux0 % aux1;
	return ;
}
