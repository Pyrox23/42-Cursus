/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:55:14 by ramo-cou          #+#    #+#             */
/*   Updated: 2025/11/04 20:43:25 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(unsigned char byte, int pid)
{
	int	i;
	int	val;

	i = 7;
	val = 0;
	while (i >= 0)
	{
		val = byte >> i;
		if (val % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(250); //Puede que haya que subir este numero, con mucho texto se pierden señales, no se si hay otra manera de arreglarlo
		i--;
	}
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	flag;
	int	i;

	if (ac != 3)
		return (write(2, "Incorrect quantity of parameters\n", 33), 1);
	flag = 0;
	server_pid = check_input(av[1], &flag);
	if (flag)
		return (write(2, "PID specified is not an int\n", 28), 1);
	i = 0;
	while (av[2][i])
		send_byte(av[2][i++], server_pid);
	send_byte(0, server_pid);
	return (0);
}
