/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:29:03 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/20 02:27:54 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->print_m, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->dead_m, NULL) != 0)
		return (1);
	i = 0;
	data->forks = malloc(data->philo_count * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (1);
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL) != 0)
			return (1);
	}
	pthread_mutex_lock(&data->dead_m);
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(data->philo_count * sizeof(t_philo));
	if (!data->philos)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].position = i + 1;
		data->philos[i].lfork = i;
		data->philos[i].rfork = (i + 1) % data->philo_count;
		data->philos[i].is_eating = 0;
		data->philos[i].eat_count = 0;
		if (pthread_mutex_init(&data->philos[i].eat_m, NULL) != 0)
			return (1);
		if (pthread_mutex_init(&data->philos[i].mutex, NULL) != 0)
			return (1);
		pthread_mutex_lock(&data->philos[i].eat_m);
		data->philos[i++].state = data;
	}
	return (0);
}

int	check(int argc, char*argv[], t_args *args)
{
	*args = ft_parser(argc, argv);
	if (is_args_error(*args))
		return (1);
	return (0);
}

int	init(t_data *data, t_args args)
{
	data->forks = NULL;
	data->philos = NULL;
	data->philo_count = args.number_of_philos;
	data->max_eat = args.number_of_eats;
	data->start_time = gettimenow();
	data->time_to_die = (uint64_t) args.time_to_die;
	data->time_to_eat = (uint64_t) args.time_to_eat;
	data->time_to_sleep = (uint64_t) args.time_to_sleep;
	if (init_philos(data))
		return (1);
	return (init_mutexes(data));
}
