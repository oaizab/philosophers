/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 02:07:42 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/21 07:34:09 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
			sem_wait(data->philos[i++].eat_s);
		times++;
	}
	sem_post(data->dead_s);
	return (NULL);
}

void	*alive_c(void *philo_v)
{
	t_philo	*philo;

	philo = philo_v;
	while (1)
	{
		sem_wait(philo->philo_s);
		if (!philo->is_eating && gettimenow() > philo->limit)
		{
			print_msg(philo, DEAD);
			sem_post(philo->philo_s);
			sem_post(philo->state->dead_s);
			return (NULL);
		}
		sem_post(philo->philo_s);
		usleep(1000);
	}
	return (NULL);
}
