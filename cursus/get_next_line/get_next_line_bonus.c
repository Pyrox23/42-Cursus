/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:36:27 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/18 20:55:04 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	merge(char *ret, char **dest, char *buff, size_t nbytes)
{
	size_t	i;

	i = 0;
	while (dest[0][i])
	{
		ret[i] = dest[0][i];
		i++;
	}
	ft_memmove(ret + i, buff, nbytes);
	ret[i + nbytes] = 0;
	free(dest[0]);
	if (nbytes != BUFFER_SIZE)
	{
		ft_memmove(buff, buff + nbytes, BUFFER_SIZE - nbytes);
		ft_bzero(buff + BUFFER_SIZE - nbytes, nbytes);
	}
	else
		ft_bzero(buff, BUFFER_SIZE + 1);
	dest[0] = ret;
}

long long	ft_append(char **dest, char *buff, size_t nbytes)
{
	char	*ret;
	size_t	d_len;

	if (!buff[0])
		return (0);
	if (!dest[0])
	{
		ret = (char *) malloc((nbytes + 1) * sizeof(char));
		if (!ret)
			return (ft_bzero(buff, BUFFER_SIZE + 1), -1);
		ft_memmove(ret, buff, nbytes);
		if (nbytes != BUFFER_SIZE)
		{
			ft_memmove(buff, buff + nbytes, BUFFER_SIZE - nbytes);
			ft_bzero(buff + BUFFER_SIZE - nbytes, nbytes);
		}
		else
			ft_bzero(buff, nbytes + 1);
		return (ret[nbytes] = 0, dest[0] = ret, 0);
	}
	d_len = ft_strlen(dest[0]);
	ret = malloc((nbytes + d_len + 1) * sizeof(char));
	if (!ret)
		return (ft_bzero(buff, BUFFER_SIZE + 1), -1);
	return (merge(ret, dest, buff, nbytes), 0);
}

void	failed_read(char **res)
{
	if (res && res[0])
	{
		free(res[0]);
		res[0] = NULL;
	}
}

int	manage_buff(char **buff, long long mode)
{
	if (mode <= 0)
	{
		free(buff[0]);
		buff[0] = NULL;
		return (1);
	}
	if (!buff)
		return (0);
	if (buff[0])
		return (1);
	buff[0] = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff[0])
		return (0);
	return (ft_bzero(buff[0], BUFFER_SIZE + 1), 1);
}

char	*get_next_line(int fd)
{
	char		*res;
	long long	bytes;
	size_t		nl;
	static char	*buff[4096];

	bytes = BUFFER_SIZE;
	nl = 0;
	res = NULL;
	if (fd < 0 || (!buff[fd] && !manage_buff(&buff[fd], 1)))
		return (NULL);
	while (bytes > 0 && !nl)
	{
		nl = ft_find(buff[fd], ft_strlen(buff[fd]));
		if (!nl)
		{
			bytes = ft_append(&res, buff[fd], ft_strlen(buff[fd]));
			if (bytes >= 0)
				bytes = read(fd, buff[fd], BUFFER_SIZE);
			if (bytes < 0 && res)
				failed_read(&res);
		}
		else if (bytes > 0)
			ft_append(&res, buff[fd], nl);
	}
	return (manage_buff(&buff[fd], bytes), res);
}
