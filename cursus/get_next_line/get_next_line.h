/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 20:11:25 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/10/16 19:42:24 by ramo-cou         ###   ########.fr       */
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

/*La solucion al bonus es utilizar una lista enlazada para guardar tanto el buffer como el numero del file descriptor al que esta asociado dicho buffer.
Hay que hacer un struct donde haya 1 int que guarde el file descriptor y un buffer[SIZE]. Como el contenido es void en una lista enlazada, se puede guardar
lo que sea en el nodo, tienes 12 funciones crack y 2 para que funcione en la version normal.*/

#endif