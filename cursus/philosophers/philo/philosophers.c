/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:57:24 by ramo-cou          #+#    #+#             */
/*   Updated: 2026/02/27 20:31:41 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	sleep_philo(t_philo *data, unsigned long time, int print)
{
	unsigned long	end_sleep;
	unsigned long	last;

	end_sleep = get_time_ms() + time;
	if (print)
	{
		data->last_meal = get_time_ms();
		print_status(SLEEP, data);
	}
	last = get_time_ms();
	while (last < end_sleep && !data->common->end
		&& (data->last_meal + data->common->t_die) > last)
	{
		usleep(100);
		last = get_time_ms();
	}
	return ((data->last_meal + data->common->t_die) <= last);
}

int	think_n_eat(t_philo *data)
{
	int	max_fork;
	int	min_fork;
	int	death;

	max_fork = max_min(data->id, data->other_fork, 0);
	min_fork = max_min(data->id, data->other_fork, 1);
	if (data->common->end)
		return (0);
	print_status(THINK, data);
	pthread_mutex_lock(&data->common->forks[min_fork]);
	print_status(FORK, data);
	pthread_mutex_lock(&data->common->forks[max_fork]);
	print_status(FORK, data);
	print_status(EATING, data);
	death = sleep_philo(data, data->common->t_eat, 0);
	pthread_mutex_unlock(&data->common->forks[min_fork]);
	pthread_mutex_unlock(&data->common->forks[max_fork]);
	if (death)
		return (1);
	data->last_meal = get_time_ms();
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
	if (!data->common->n_eat)
		return (print_status(END, data), NULL);
	if (data->common->n_philos == 1)
		return (alone_rutine(data), NULL);
	times_ate = 0;
	data->last_meal = get_time_ms();
	death = ((data->last_meal + data->common->t_die) <= get_time_ms());
	while (!death && !data->common->end)
	{
		if (think_n_eat(data) || sleep_philo(data, data->common->t_sleep, 1))
			death = 1;
		if (data->common->until_death == 5)
			check_end(++times_ate, data);
	}
	if (death)
		return (print_status(DEATH, data), NULL);
	return (print_status(END, data), NULL);
}

/*
	if (data->common->until_death == 5)
	{
		times_ate++;
		if (data->common->n_eat == times_ate)
			data->common->philo_finish++;
	}
*/
/* check_end(); */
