/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:50:55 by ramo-cou          #+#    #+#             */
/*   Updated: 2026/02/27 19:57:39 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define MAX_THREADS 256
# define SLEEP 1
# define FORK 2
# define EATING 3
# define THINK 4
# define DEATH 5
# define END 6
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	unsigned long	t_die;
	unsigned int	t_eat;
	unsigned long	t_sleep;
	unsigned int	n_eat;
	int				until_death;
	pthread_mutex_t	*console;
	pthread_mutex_t	*forks;
	int				n_philos;
	int				end;
	int				philo_finish;
}	t_data;

typedef struct s_philo
{
	t_data			*common;
	int				id;
	pthread_t		tid;
	int				other_fork;
	unsigned long	last_meal;
}	t_philo;

size_t			get_str_len(char *str);
int				compare_strings(const char *s1, const char *s2, size_t n);
char			*trim(char *str);
int				ft_atol(const char *str);
t_philo			**check_arguments(char **av, int ac);
int				stop_p(t_philo **table, t_data *ref);
void			print_nbr(int n, int fd);
void			*philosophy(void *arg);
int				max_min(int a, int b, int mode);
unsigned long	get_time_ms(void);
int				sleep_philo(t_philo *data, unsigned long time, int print);
void			print_status(int code, t_philo *data);
void			alone_rutine(t_philo *data);

#endif