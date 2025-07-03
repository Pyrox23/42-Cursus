/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:03:30 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/23 18:15:25 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int		size;
	int		i;

	if (range == NULL)
		return (-1);
	size = max - min;
	if (size <= 0)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	range[0] = (int *) malloc(sizeof(int) * size);
	while (i < size)
	{
		range[0][i] = min + i;
		i++;
	}
	return (size);
}
