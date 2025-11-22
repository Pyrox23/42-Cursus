/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:16:23 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/22 18:44:51 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_state = 0;

void	read_size(size_t *size, int sig, int *bit, int pid)
{
	usleep(LAT);
	*size += (sig == SIGUSR1);
	if ((*bit)++ < 64)
		*size = *size << 1;
	kill(pid, SIGUSR1);
}

void	add_bit(t_minitalk *data, int sig)
{
	usleep(LAT);
	data->c += (sig == SIGUSR1);
	if (++data->moves < 8)
		data->c = data->c << 1;
	data->sig = SIGUSR1;
	if (data->moves == 8)
	{
		*(data->dummy++) = data->c;
		data->moves = 0;
		if (!data->c)
		{
			end_conn_server(data, NULL);
			g_state = 0;
			data->sig = SIGUSR2;
		}
		if ((size_t)(data->dummy - data->str) >= data->len)
		{
			end_conn_server(data, "Exceeded size sent\n");
			g_state = 0;
		}
		data->c = 0;
	}
	kill(data->pid, data->sig);
}

int	init_struct(t_minitalk *data, size_t size, int pid)
{
	data->pid = pid;
	data->len = size + 1;
	data->str = malloc(data->len * sizeof(char));
	if (!data->str)
		return (0);
	data->dummy = data->str;
	data->moves = 0;
	data->sig = 0;
	g_state = 1;
	return (1);
}

void	sig_handler_serv(int sig, siginfo_t *info, void *content)
{
	static t_minitalk	data;
	static size_t		size = 0;
	static int			bit = 0;

	(void) content;
	if (!g_state && bit < 64)
		read_size(&size, sig, &bit, info->si_pid);
	else if (g_state == 2)
		end_conn_server(&data, "Abort, no response from client\n");
	else
	{
		if (!g_state && !init_struct(&data, size, info->si_pid))
			end_conn_server(&data, "Malloc Error!\n");
		else
			add_bit(&data, sig);
		bit = 0;
	}
}

int	main(void)
{
	int	counter;

	if (!init_signal(sig_handler_serv))
		return (write(2, "Signal Error!\n", 15), 1);
	counter = 0;
	ft_printf("Server started!\nPID: %d\n", getpid());
	while (1)
	{
		if (!usleep(MAX_TIMEOUT))
		{
			if (counter == 2 && g_state)
			{
				g_state = 2;
				kill(getpid(), SIGUSR1);
				g_state = 0;
				counter = -1;
			}
			counter++;
		}
		else
			counter = 0;
	}
	return (0);
}
