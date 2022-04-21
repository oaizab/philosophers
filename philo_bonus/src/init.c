/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:29:03 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/21 07:40:22 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_semaphores(t_data *data)
{
	int	i;

	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_DEAD);
	sem_unlink(SEM_FORK);
	data->print_s = ft_sem_open(SEM_PRINT, 1);
	if (data->print_s == SEM_FAILED)
		return (1);
	data->dead_s = ft_sem_open(SEM_DEAD, 0);
	if (data->dead_s == SEM_FAILED)
		return (1);
	i = 0;
	data->forks = ft_sem_open(SEM_FORK, data->philo_count);
	if (data->forks == SEM_FAILED)
		return (1);
	return (0);
}

int	init_philos(t_data *data)
{
	int		i;
	char	semaphore[50];

	data->philos = malloc(data->philo_count * sizeof(t_philo));
	if (!data->philos)
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].position = i + 1;
		data->philos[i].is_eating = 0;
		data->philos[i].eat_count = 0;
		get_sem_name(SEM_EAT, semaphore, i);
		sem_unlink(semaphore);
		data->philos[i].eat_s = ft_sem_open(semaphore, 0);
		if (data->philos[i].eat_s == SEM_FAILED)
			return (1);
		get_sem_name(SEM_PHILO, semaphore, i);
		sem_unlink(semaphore);
		data->philos[i].philo_s = ft_sem_open(semaphore, 1);
		if (data->philos[i].philo_s == SEM_FAILED)
			return (1);
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
	return (init_semaphores(data));
}
