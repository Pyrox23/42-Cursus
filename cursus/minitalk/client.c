/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:55:14 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/22 18:45:09 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_status = 1;

void	send_bit(t_minitalk *data)
{
	usleep(LAT);
	if (!data->moves)
	{
		data->moves = 8;
		data->dummy++;
	}
	if (data->dummy == data->str + data->len)
		data->sig = SIGUSR2;
	else
	{
		data->c = *(data->dummy) >> (--data->moves);
		if (data->c % 2)
			data->sig = SIGUSR1;
		else
			data->sig = SIGUSR2;
	}
	kill(data->pid, data->sig);
}

void	send_len(t_minitalk *data)
{
	usleep(LAT);
	data->c = data->len >> (--data->moves);
	if (data->c % 2)
		data->sig = SIGUSR1;
	else
		data->sig = SIGUSR2;
	kill(data->pid, data->sig);
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		g_status = 1;
	if (sig == SIGUSR2)
		g_status = 0;
}

int	main_loop(t_minitalk *data)
{
	int	conn;

	conn = 1;
	ft_printf("Client started!\nPID: %d\n", getpid());
	while (g_status && data->moves && conn)
	{
		send_len(data);
		conn = usleep(MAX_TIMEOUT);
	}
	data->moves = 8;
	while (g_status && conn)
	{
		send_bit(data);
		conn = usleep(MAX_TIMEOUT);
	}
	if (g_status)
		return (write(2, "Error: No response from server\n", 31), 1);
	else if (data->dummy != data->str + data->len)
		return (write(2, "Server terminated connection early\n", 35), 1);
	else
		write(1, "Message sent!\n", 14);
	return (0);
}

int	main(int ac, char **av)
{
	struct sigaction	act;
	t_minitalk			data;

	if (ac != 3)
		return (write(2, "Use of client: ./client <PID> <Message>\n", 40), 1);
	data.pid = ft_atoi(av[1]);
	if (data.pid <= 0)
		return (write(2, "PID specified is not valid (<= 0)\n", 34), 1);
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_handler = sig_handler;
	act.sa_flags = 0;
	act.sa_restorer = NULL;
	if (sigaction(SIGUSR1, &act, NULL) == -1 || sigaction(SIGUSR2, &act, NULL)
		== -1)
		return (write(2, "Signal Error!\n", 15), 1);
	data.str = av[2];
	data.dummy = data.str;
	data.len = ft_strlen(data.str);
	data.moves = 64;
	data.c = 0;
	return (main_loop(&data));
}
