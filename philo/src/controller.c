/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 02:07:42 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/20 02:40:39 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eat_count_c(void *data_v)
{
	t_data	*data;
	int		i;
	int		times;

	data = data_v;
	times = 0;
	while (times < data->max_eat)
	{
		i = 0;
		while (i < data->philo_count)
			pthread_mutex_lock(&data->philos[i++].eat_m);
		times++;
	}
	pthread_mutex_unlock(&data->dead_m);
	return (NULL);
}

void	*alive_c(void *philo_v)
{
	t_philo	*philo;

	philo = philo_v;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (!philo->is_eating && gettimenow() > philo->limit)
		{
			print_msg(philo, DEAD);
			pthread_mutex_unlock(&philo->mutex);
			pthread_mutex_unlock(&philo->state->dead_m);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->mutex);
		usleep(1000);
	}
	return (NULL);
}
