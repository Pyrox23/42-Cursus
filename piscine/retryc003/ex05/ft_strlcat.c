/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:35:20 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/26 16:51:43 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlen(char *str)
{
	unsigned int		len;

	len = 0;
	while (*(str + len) != 0)
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int		dest_len;
	unsigned int		i;

	dest_len = ft_strlen(dest);
	i = 0;
	if (size != 0)
	{
		if (size <= dest_len)
			return (ft_strlen(src) + size);
		while (src[i] != 0 && i < size - dest_len - 1)
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = 0;
	}
	return (dest_len + ft_strlen(src));
}
