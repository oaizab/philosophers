/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:24:23 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/21 06:57:21 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	start_counter(t_data *data)
{
	pthread_t	th;

	if (data->max_eat >= 0)
	{
		if (pthread_create(&th, NULL, eat_count_c, (void *) data) != 0)
			return (1);
		pthread_detach(th);
	}
	return (0);
}

int	start_philos(t_data *data)
{
	int			i;

	if (start_counter(data))
		return (1);
	i = 0;
	while (i < data->philo_count)
	{
		data->philos[i].pid = fork();
		if (data->philos[i].pid < 0)
			return (1);
		if (data->philos[i].pid == 0)
		{
			routine(&data->philos[i]);
			exit(0);
		}
		usleep(100);
		i++;
	}
	return (0);
}
