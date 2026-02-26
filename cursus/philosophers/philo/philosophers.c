/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:57:24 by ramo-cou          #+#    #+#             */
/*   Updated: 2026/02/26 20:22:02 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(int code, t_philo *data, unsigned long time)
{
	if (!pthread_mutex_lock(data->common->console))
	{
		printf("[%ld] %d has accessed the console, code sent: %d\n", time, data->id + 1, code);
		pthread_mutex_unlock(data->common->console);
	}
	else
		printf("For some reason lock didn't work lol\n");
}

unsigned long	get_time_ms(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((unsigned long)((tp.tv_sec * 1000) + (tp.tv_usec / 1000)));
}

void	sleep_philo(t_philo *data, unsigned long time, int print)
{
	unsigned long	end_sleep;

	end_sleep = get_time_ms() + time;
	if (print)
		print_status(SLEEP, data, get_time_ms());
	while (get_time_ms() < end_sleep)
		usleep(100);
}

int	think_n_eat(t_philo *data)
{
	print_status(THINK, data, get_time_ms());
	if (!pthread_mutex_lock(&data->common->forks[data->id])
		&& (data->common->n_philos == 1
			|| !pthread_mutex_lock(&data->common->forks[data->other_fork])))
	{
		print_status(EATING, data, get_time_ms());
		sleep_philo(data, data->common->t_eat, 0);
		pthread_mutex_unlock(&data->common->forks[data->id]);
		if (data->common->n_philos != 1)
			pthread_mutex_unlock(&data->common->forks[data->other_fork]);
		data->last_meal = get_time_ms();
		print_status(THINK, data, get_time_ms());
	}
	else
		printf("For some reason lock didn't work lol\n");
	return ((data->last_meal + data->common->t_die) <= get_time_ms());
}

void	*philosophy(void *arg)
{
	t_philo			*data;
	unsigned int	times_ate;
	int				death;

	if (!arg)
		return (NULL);
	data = (t_philo *) arg;
	times_ate = 0;
	death = 0;
	data->last_meal = get_time_ms();
	while (data->common->n_eat > times_ate && !death)
	{
		death = think_n_eat(data);
		if (!death)
			sleep_philo(data, data->common->t_sleep, 1);
		else
			print_status(DEATH, data, get_time_ms());
		if (data->common->until_death == 5)
			times_ate++;
	}
	print_status(END, data, get_time_ms());
	data->common->end = 1;
	return (NULL);
}
