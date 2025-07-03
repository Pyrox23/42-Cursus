/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:01:11 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/19 17:12:30 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb);

int	sqrt_rec(int nb, int root)
{
	if (root * root == nb)
		return (root);
	if (root > nb / 2)
		return (0);
	return (sqrt_rec(nb, root + 1));
}

int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	return (sqrt_rec(nb, 1));
}
