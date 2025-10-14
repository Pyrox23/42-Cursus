/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:11:21 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/14 23:56:08 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*merge(char *ret, char *dest, char *buff, size_t nbytes)
{
	size_t	i;

	i = 0;
	while (dest[i])
	{
		ret[i] = dest[i];
		i++;
	}
	ft_memmove(ret + i, buff, nbytes);
	ret[i + nbytes] = 0;
	free(dest);
	if (nbytes != SIZE)
	{
		ft_memmove(buff, buff + nbytes, SIZE - nbytes);
		ft_bzero(buff + SIZE - nbytes, nbytes);
	}
	else
		ft_bzero(buff, nbytes);
	return (ret);
}

char	*ft_append(char *dest, char *buff, size_t nbytes)
{
	char	*ret;
	size_t	d_len;

	if (!dest)
	{
		ret = (char *) malloc((nbytes + 1) * sizeof(char));
		ft_memmove(ret, buff, nbytes);
		if (nbytes != SIZE)
		{
			ft_memmove(buff, buff + nbytes, SIZE - nbytes);
			ft_bzero(buff + SIZE - nbytes, nbytes);
		}
		else
			ft_bzero(buff, nbytes);
		ret[nbytes] = 0;
		return (ret);
	}
	d_len = ft_strlen(dest);
	ret = malloc((nbytes + d_len + 1) * sizeof(char));
	return (merge(ret, dest, buff, nbytes));
}

char	*get_next_line(int fd)
{
	char		*res;
	long long	bytes;
	size_t		eol;
	static char	buff[SIZE] = "";

	bytes = 1;
	eol = 0;
	res = NULL;
	while (bytes > 0 && !eol)
	{
		eol = ft_find(buff, bytes);
		if (!eol)
		{
			if (buff[0])
				res = ft_append(res, buff, SIZE);
			bytes = read(fd, buff, SIZE);
		}
		else if (bytes)
			res = ft_append(res, buff, eol);
	}
	return (res);
}
