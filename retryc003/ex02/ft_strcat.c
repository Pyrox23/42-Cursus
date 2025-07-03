/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:29:51 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/06/17 14:59:15 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src);

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*(str + len) != 0)
		len = len + 1;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int		dest_len;
	int		i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != 0)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	return (dest);
}
