/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:16:23 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/06 01:37:39 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_minitalk	g_data;

void	end_program(int sig)
{
	if (g_data.str)
		free(g_data.str);
	if (sig == SIGINT)
	{
		ft_printf("Bye!\n");
		exit(EXIT_SUCCESS);
	}
	write(2, "Realloc error!\n", 15);
	exit(EXIT_FAILURE);
}

void	manage_str(void)
{
	*(g_data.dummy) = g_data.c;
	g_data.dummy++;
	if (!g_data.c)
	{
		ft_printf("Client: %s\n", g_data.str);
		g_data.dummy = g_data.str;
	}
	if ((g_data.dummy - g_data.str) >= g_data.len && ft_realloc(&g_data))
		end_program(1);
	g_data.c = 0;
	g_data.moves = 0;
}

void	add_bit(int sig)
{
	if (sig == SIGUSR1)
	{
		g_data.c += 1;
		if (++g_data.moves < 8)
			g_data.c = g_data.c << 1;
	}
	else
	{
		if (++g_data.moves < 8)
			g_data.c = g_data.c << 1;
	}
	if (g_data.moves == 8)
		manage_str();
}

void	init_signal(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	act.sa_handler = add_bit;
	act.sa_flags = 0;
	act.sa_flags |= SA_SIGINFO;
	act.sa_restorer = NULL;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigemptyset(&act.sa_mask);
	act.sa_handler = end_program;
	act.sa_flags = 0;
	act.sa_restorer = NULL;
	sigaction(SIGINT, &act, NULL);
}

int	main(void)
{
	init_signal();
	g_data.c = 0;
	g_data.moves = 0;
	g_data.len = 128;
	g_data.str = malloc(g_data.len * sizeof(char));
	if (!g_data.str)
		return (write(2, "Malloc error!\n", 14), 1);
	g_data.dummy = g_data.str;
	ft_printf("Server started!\nPID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
