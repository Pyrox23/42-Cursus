/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:54:16 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/09/30 15:54:16 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;
	size_t	i;
	char	ch;

	occ = NULL;
	i = 0;
	ch = (char) c;
	while (s[i])
	{
		if (s[i] == ch)
			occ = (char *) s + i;
		i++;
	}
	if (!occ && s[i] == ch)
		occ = (char *) s + i;
	return (occ);
}
