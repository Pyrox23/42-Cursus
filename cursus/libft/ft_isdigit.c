/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:43:36 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/09/29 12:44:45 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int ft_isdigit(int c);

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (2048);
    return (0);
}

/*int	main(int argc, char **argv)
{
	char	c;

	c = 32;
	while (c <= 126)
	{
		printf("%c: %d, %d\n", c, ft_isalpha(c), isalpha(c));
		c++;
	}
	return (0);
}*/

