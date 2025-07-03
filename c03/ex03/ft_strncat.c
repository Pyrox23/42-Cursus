/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:45:16 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/17 16:29:36 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*(str + len) != 0)
		len = len + 1;
	return (len);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int		dest_len;
	unsigned int		i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != 0 && i < nb)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	return (dest);
}
