/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:07:53 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/21 00:35:10 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
	{
	int	sign;
	int	nbr;
	int	i;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] <= '9' && str[i] >= '0')
		nbr = nbr * 10 + (str[i++] - '0');
	return (nbr * sign);
}

void	init_signal(void (*f)(int, siginfo_t*, void*))
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_sigaction = f;
	act.sa_flags = SA_SIGINFO;
	act.sa_restorer = NULL;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

void	end_conn_server(t_minitalk *data, char *msg)
{
	if (!msg)
		ft_printf("Client %d: %s\n", data->pid, data->str);
	else
		write(2, msg, ft_strlen(msg));
	free(data->str);
	data->str = NULL;
	data->dummy = NULL;
}
