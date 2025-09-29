/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:33:05 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/07/02 15:35:21 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <unistd.h>
#include <stdlib.h>
#define SIZE 1024

unsigned long long	get_size(int file);
char				*ft_append(char *m1, char *m2);

char	*open_standard(void)
{
	char				*res;
	unsigned long		checking;
	char				buff[SIZE + 1];

	res = malloc(sizeof(char) * (SIZE + 1));
	checking = SIZE;
	while (checking > 0)
	{
		checking = read(0, buff, SIZE);
		buff[checking] = 0;
		if (checking > 0)
			res = ft_append(res, buff);
	}
	return (res);
}
