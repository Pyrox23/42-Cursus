/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:31:40 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/09/30 15:31:40 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*occ;
	size_t	i;

	if (!s)
		return (NULL);
	occ = NULL;
	i = 0;
	while (!occ && s[i])
	{
		if (s[i] == c)
			occ = (char *) s + i;
		i++;
	}
	if (!occ && s[i] == c)
		occ = (char *) s + i;
	return (occ);
}
