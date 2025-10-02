/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:47:11 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/02 20:53:53 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	act_size;
	size_t	i;

	act_size = 0;
	while (s[start + act_size] && act_size < len)
		act_size++;
	ss = (char *) ft_calloc(act_size + 1, sizeof(char));
	if (!ss)
		return (NULL);
	i = 0;
	while (i < act_size)
	{
		ss[i] = s[start + i];
		i++;
	}
	ss[i] = 0;
	return (ss);
}
