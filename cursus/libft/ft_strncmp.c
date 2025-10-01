/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:28:03 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/01 10:33:01 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		comp;
	size_t	i;

	comp = 0;
	i = 0;
	while (!comp && s1[i] && s2[i] && i < n)
	{
		comp = s1[i] - s2[i];
		i++;
	}
	if (!comp && n)
		return (s1[i] - s2[i]);
	return (comp);
}
