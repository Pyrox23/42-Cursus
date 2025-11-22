/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:16:52 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/22 01:08:07 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include "ft_printf.h"
# define LAT 100
# define MAX_TIMEOUT 500000

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

int		ft_atoi(const char *nptr);
void	end_conn_server(t_minitalk *data, char *msg);
void	sig_handler_serv(int sig, siginfo_t *info, void *content);
void	init_signal(void (*f)(int, siginfo_t*, void*));

#endif