/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 19:55:54 by ramo-cou          #+#    #+#             */
/*   Updated: 2026/02/27 19:57:42 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	get_time_ms(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((unsigned long)tp.tv_sec * 1000UL
		+ (unsigned long)tp.tv_usec / 1000UL);
}

void	print_status(int code, t_philo *data)
{
	if (data->common->end)
		return ;
	pthread_mutex_lock(data->common->console);
	if (code == SLEEP)
		printf("[%ld] %d is sleeping\n", get_time_ms(), data->id + 1);
	else if (code == FORK)
		printf("[%ld] %d has taken a fork\n", get_time_ms(), data->id + 1);
	else if (code == EATING)
		printf("[%ld] %d is eating\n", get_time_ms(), data->id + 1);
	else if (code == THINK)
		printf("[%ld] %d is thinking\n", get_time_ms(), data->id + 1);
	else if (code == DEATH)
		printf("[%ld] %d died\n", get_time_ms(), data->id + 1);
	else if (code == END)
		printf("The simulation has ended\n");
	pthread_mutex_unlock(data->common->console);
}

static int	lonely_philosopher_eat(t_philo *data)
{
	int	death;

	print_status(THINK, data);
	pthread_mutex_lock(&data->common->forks[data->id]);
	print_status(FORK, data);
	print_status(EATING, data);
	death = sleep_philo(data, data->common->t_eat, 0);
	pthread_mutex_unlock(&data->common->forks[data->id]);
	if (death)
		return (1);
	data->last_meal = get_time_ms();
	return ((data->last_meal + data->common->t_die) <= get_time_ms());
}

void	alone_rutine(t_philo *data)
{
	unsigned int	times_ate;
	int				death;

	times_ate = 0;
	data->last_meal = get_time_ms();
	death = ((data->last_meal + data->common->t_die) <= get_time_ms());
	while (!death && times_ate < data->common->n_eat)
	{
		if (lonely_philosopher_eat(data)
			|| sleep_philo(data, data->common->t_sleep, 1))
			death = 1;
		if (data->common->until_death == 5)
			times_ate++;
	}
	if (death)
		print_status(DEATH, data);
	else
		print_status(END, data);
}
