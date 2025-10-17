/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:36:27 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/17 18:53:54 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	merge(char *ret, char **dest, char *buff, size_t nbytes)
{
	size_t	i;

	i = 0;
	while (*dest[i])
	{
		ret[i] = *dest[i];
		i++;
	}
	ft_memmove(ret + i, buff, nbytes);
	ret[i + nbytes] = 0;
	free(*dest);
	if (nbytes != BUFFER_SIZE)
	{
		ft_memmove(buff, buff + nbytes, BUFFER_SIZE - nbytes);
		ft_bzero(buff + BUFFER_SIZE - nbytes, nbytes);
	}
	else
		ft_bzero(buff, nbytes);
	*dest = ret;
	return (0);
}

size_t	ft_append(char **dest, char *buff, size_t nbytes)
{
	char	*ret;
	size_t	d_len;

	if (!*dest)
	{
		ret = (char *) malloc((nbytes + 1) * sizeof(char));
		if (!ret)
			return (1);
		ft_memmove(ret, buff, nbytes);
		if (nbytes != BUFFER_SIZE)
		{
			ft_memmove(buff, buff + nbytes, BUFFER_SIZE - nbytes);
			ft_bzero(buff + BUFFER_SIZE - nbytes, nbytes);
		}
		else
			ft_bzero(buff, nbytes);
		ret[nbytes] = 0;
		*dest = ret;
		return (0);
	}
	d_len = ft_strlen(*dest);
	ret = malloc((nbytes + d_len + 1) * sizeof(char));
	if (!ret)
		return (failed_read(dest), ft_bzero(buff, nbytes), 1);
	return (merge(ret, dest, buff, nbytes));
}

void	failed_read(char **res)
{
	if (res && *res)
	{
		free(*res);
		res = NULL;
	}
}

char	*get_next_line(int fd)
{
	char		*res;
	long long	bytes;
	size_t		nl;
	static char	buff[1024][BUFFER_SIZE];

	bytes = BUFFER_SIZE;
	nl = 0;
	res = NULL;
	while (bytes > 0 && !nl)
	{
		nl = ft_find(buff[fd], bytes);
		if (!nl)
		{
			if (buff[fd][0])
				nl = ft_append(&res, buff[fd], ft_strlen(buff[fd]));
			bytes = read(fd, buff[fd], BUFFER_SIZE);
			if (bytes == -1 && res)
				failed_read(&res);
		}
		else if (bytes > 0)
			nl = ft_append(&res, buff[fd], nl);
	}
	return (res);
}
