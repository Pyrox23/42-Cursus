/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:12:56 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/12 19:55:26 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char		ans;

	if (n >= 0)
	{
		ans = 'P';
		write(1, &ans, 1);
	}
	else
	{
		ans = 'N';
		write(1, &ans, 1);
	}
	return ;
}
