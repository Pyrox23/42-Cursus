/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:27:25 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/19 19:36:25 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);

int	prime_rec(int nb, int current)
{
	if (nb % current == 0)
		return (0);
	if (current >= nb / 2)
		return (1);
	return (prime_rec(nb, current + 1));
}

int	ft_is_prime(int nb)
{
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	return (prime_rec(nb, 2));
}
