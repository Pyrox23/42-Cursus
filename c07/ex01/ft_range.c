/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:12:11 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/26 11:41:18 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
int	*ft_range(int min, int max);

int	valid_integers(long min, long max)
{
	if (min > 2147483647 || min < -2147483648)
		return (0);
	if (max > 2147483647 || max < -2147483648)
		return (0);
	write(1, "valid", 5);
	return (1);
}

int	*ft_range(int min, int max)
{
	int			*arr;
	long		check_min;
	long		check_max;
	long		i;

	check_min = (long) min;
	check_max = (long) max;
	if (check_min >= check_max)
		return (NULL);
	check_max -= check_min;
	arr = (int *) malloc(sizeof(int) * check_max);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < check_max)
	{
		arr[i] = (int) (min + i);
		i++;
	}
	return (arr);
}
