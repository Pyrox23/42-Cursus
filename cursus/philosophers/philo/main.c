/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:52:16 by ramo-cou          #+#    #+#             */
/*   Updated: 2026/02/27 18:26:30 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	usage_message(void)
{
	write(2, "Usage: ./philo n_philos t_die t_eat t_sleep [n_eat]\n", 52);
	write(2, "n_philos (int, max 256): Number of Philosophers\n", 48);
	write(2, "t_die (uint): Time it takes to die (ms)\n", 40);
	write(2, "t_eat (uint): Time it takes to eat (ms)\n", 40);
	write(2, "t_sleep (uint): Time it takes to sleep (ms)\n", 44);
	write(2, "n_eat (uint): Number of times the Philosopher must eat\n", 55);
	return (1);
}

int	max_min(int a, int b, int mode)
{
	if (mode)
	{
		if (a < b)
			return (a);
		return (b);
	}
	if (a > b)
		return (a);
	return (b);
}

int	stop_p(t_philo **table, t_data *ref)
{
	int	i;

	i = -1;
	while (table && table[++i])
		free(table[i]);
	if (table)
		free(table);
	i = -1;
	while (ref->forks && ++i < ref->n_philos)
	{
		if (pthread_mutex_destroy(&ref->forks[i]))
		{
			write(2, "Failed to destroy mutex ", 24);
			print_nbr(i, 2);
			write(2, "\n", 1);
		}
	}
	if (ref->forks)
		free(ref->forks);
	if (ref->console)
	{
		if (pthread_mutex_destroy(&ref->forks[i]))
			write(2, "Failed to destroy console\n", 27);
		free(ref->console);
	}
	return (free(ref), 1);
}

int	init_mutexes(t_philo **table)
{
	int	i;
	int	err;

	i = -1;
	err = 0;
	while (++i < table[0]->common->n_philos && !err)
	{
		if (pthread_mutex_init(&table[0]->common->forks[i], NULL))
			err = stop_p(table, table[0]->common);
	}
	if (err || pthread_mutex_init(table[0]->common->console, NULL))
		stop_p(table, table[0]->common);
	return (err);
}

int	main(int ac, char **av)
{
	t_philo	**table;
	int		i;

	if (ac != 5 && ac != 6)
		return (usage_message());
	table = check_arguments(av + 1, ac - 1);
	if (!table)
		return (write(2, "Invalid Arguments\n", 18), 1);
	if (init_mutexes(table))
		return (write(2, "Error while adding forks (mutexes)\n", 35), 1);
	i = -1;
	while (table[++i])
		pthread_create(&(table[i]->tid), NULL, philosophy, table[i]);
	i = -1;
	while (table[++i])
		pthread_join(table[i]->tid, NULL);
	stop_p(table, table[0]->common);
	return (0);
}
