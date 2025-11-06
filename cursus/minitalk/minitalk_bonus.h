/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:16:52 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/06 01:42:50 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct s_minitalk
{
	char		*str;
	char		*dummy;
	int			c;
	int			moves;
	long int	len;
	int			pid;
	int			sig;
}	t_minitalk;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_realloc(t_minitalk *g_data);
void	*ft_memmove(void *dest, const void *src, size_t len);
int		ft_atoi(const char *nptr);

#endif