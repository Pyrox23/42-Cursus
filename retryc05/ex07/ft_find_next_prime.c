/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:50:50 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/20 12:11:32 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb);

int	prime_rec(int nb, int current)
{
	if (nb % current == 0)
		return (0);
	if (current >= nb / 2)
		return (1);
	return (prime_rec(nb, current + 1));
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (prime_rec(nb, 2) != 1)
		nb++;
	return (nb);
}
