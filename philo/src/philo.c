/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:24:23 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/21 02:58:52 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philos(t_data *data)
{
	pthread_t	th;
	int			i;

	if (data->max_eat >= 0)
	{
		if (pthread_create(&th, NULL, eat_count_c, (void *) data) != 0)
			return (1);
		pthread_detach(th);
	}
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&th, NULL, routine, (void *) &data->philos[i]))
			return (1);
		pthread_detach(th);
		usleep(100);
		i++;
	}
	return (0);
}
