/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:55:14 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/06 01:29:49 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_minitalk	g_data;

void	send_bit(int sig)
{
	if (sig == SIGUSR1)
		write(1, "ACK\n", 4);
	usleep(200);
	if (!g_data.moves)
	{
		g_data.moves = 8;
		g_data.dummy++;
	}
	if (g_data.dummy == g_data.str + g_data.len)
		g_data.sig = SIGUSR2;
	else
	{
		g_data.c = *(g_data.dummy) >> (--g_data.moves);
		if (g_data.c % 2)
			g_data.sig = SIGUSR1;
		else
			g_data.sig = SIGUSR2;
	}
}

void	end_program_client(int sig)
{
	if (sig == SIGUSR2)
		write(1, "ACK\n", 4);
	if (g_data.dummy == g_data.str + g_data.len)
	{
		write(1, "Message sent!\n", 14);
		exit(EXIT_SUCCESS);
	}
	write(2, "Server terminated connection early\n", 35);
	exit(EXIT_FAILURE);
}

void	init_signal(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_handler = send_bit;
	act.sa_flags = 0;
	act.sa_restorer = NULL;
	sigaction(SIGUSR1, &act, NULL);
	act.sa_handler = end_program_client;
	sigaction(SIGUSR2, &act, NULL);
	sigemptyset(&act.sa_mask);
	g_data.moves = 8;
	g_data.c = 0;
	g_data.sig = 0;
}

int	main(int ac, char **av)
{
	int	conn;

	if (ac != 3)
		return (write(2, "Use of client: ./client <PID> <Message>\n", 40), 1);
	g_data.pid = ft_atoi(av[1]);
	if (g_data.pid <= 0)
		return (write(2, "PID specified is not valid (<= 0)\n", 34), 1);
	init_signal();
	g_data.str = av[2];
	g_data.dummy = g_data.str;
	g_data.len = ft_strlen(av[2]);
	conn = 1;
	ft_printf("Client started!\nPID: %d\n", getpid());
	send_bit(1);
	while (conn)
	{
		if (g_data.sig)
			kill(g_data.pid, g_data.sig);
		conn = usleep(2000000);
	}
	write(2, "Error: No response from server\n", 31);
	return (0);
}
