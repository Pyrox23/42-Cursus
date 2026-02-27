/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramo-cou <ramo-cou@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:30:33 by ramo-cou          #+#    #+#             */
/*   Updated: 2026/02/27 19:03:00 by ramo-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_limits(char *nb)
{
	size_t	ln;
	char	sign;

	sign = nb[0];
	if (sign == '+')
		nb++;
	ln = get_str_len(nb);
	if (ln > 10 && nb[0] == '0')
	{
		while (nb && *nb == '0')
			nb++;
		ln = get_str_len(nb);
	}
	return (ln > 10 || (ln == 10 && compare_strings("4294967295", nb, 10) < 0));
}

static int	str_is_uint(char *str)
{
	int	i;
	int	err;

	if (!*str)
		return (1);
	if (*str == '-' && get_str_len(str) == 2 && *(str + 1) == '0')
		return (0);
	i = 0;
	err = 0;
	while (str[i] && !err)
	{
		if (str[i] == '+' && i == 0 && str[i + 1])
			i++;
		err = !(str[i] >= '0' && str[i] <= '9');
		i++;
	}
	if (!err)
		return (check_limits(str));
	return (err);
}

static t_philo	**create_struct(t_data *ref)
{
	t_philo			**table;
	int				i;
	int				err;

	table = malloc((ref->n_philos + 1) * sizeof(t_philo *));
	if (!table)
		return (stop_p(NULL, ref), NULL);
	i = -1;
	err = 0;
	while (++i < ref->n_philos && !err)
	{
		table[i] = malloc(sizeof(t_philo));
		if (!table[i])
			err = stop_p(table, ref);
		else
		{
			table[i]->common = ref;
			table[i]->id = i;
			table[i]->other_fork = (i - 1 + ref->n_philos) % ref->n_philos;
		}
	}
	if (err)
		return (NULL);
	return (table[i] = NULL, table);
}

void	create_reference(char **av, int ac, int n_philos, t_data *ref)
{
	ref->console = NULL;
	ref->n_philos = n_philos;
	ref->t_die = ft_atol(av[1]);
	ref->t_eat = ft_atol(av[2]);
	ref->t_sleep = ft_atol(av[3]);
	ref->end = 0;
	ref->philo_finish = 0;
	if (ac == 5)
		ref->n_eat = ft_atol(av[4]);
	else
		ref->n_eat = -1;
	ref->until_death = ac;
	ref->forks = malloc((n_philos) * sizeof(pthread_mutex_t));
	if (!ref->forks)
	{
		stop_p(NULL, ref);
		return ;
	}
	ref->console = malloc(sizeof(pthread_mutex_t));
	if (!ref->console)
		stop_p(NULL, ref);
}

t_philo	**check_arguments(char **av, int ac)
{
	t_data	*ref;
	int		i;
	int		err;
	int		n_philos;

	i = -1;
	err = 0;
	while (++i < ac && !err)
		err = str_is_uint(trim(av[i]));
	if (err)
		return (NULL);
	n_philos = ft_atol(av[0]);
	if (n_philos > MAX_THREADS || n_philos == 0)
		return (NULL);
	ref = malloc(sizeof(t_data));
	if (!ref)
		return (NULL);
	create_reference(av, ac, n_philos, ref);
	return (create_struct(ref));
}
