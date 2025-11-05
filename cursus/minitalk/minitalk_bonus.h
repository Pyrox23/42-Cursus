/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:16:52 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/05 21:58:17 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# define I_MIN "2147483648"
# define I_MAX "2147483647"
# include <signal.h>
# include <sys/types.h>
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
int		check_input(char *str, int *flag);
int		ft_realloc(t_minitalk *g_data);
void	*ft_memmove(void *dest, const void *src, size_t len);

#endif