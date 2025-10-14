/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:11:25 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/14 23:55:31 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifdef BUFFER_SIZE
#  define SIZE BUFFER_SIZE
# else
#  define SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>

typedef unsigned char	t_uc;

char	*get_next_line(int fd);
size_t	ft_find(char *str, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_memmove(char *dest, char *src, size_t len);
char	*merge(char *ret, char *dest, char *buff, size_t nbytes);
char	*ft_append(char *dest, char *buff, size_t nbytes);
void	ft_bzero(void *s, size_t n);

#endif