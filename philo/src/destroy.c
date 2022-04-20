/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:44:22 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/17 22:51:47 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_data(t_data data)
{
	int	i;

	if (data.philos)
	{
		i = 0;
		while (i < data.philo_count)
		{
			pthread_mutex_destroy(&data.philos[i].eat_m);
			pthread_mutex_destroy(&data.philos[i++].mutex);
		}
		free(data.philos);
	}
	if (data.forks)
	{
		i = 0;
		while (i < data.philo_count)
			pthread_mutex_destroy(&data.forks[i++]);
		free(data.forks);
	}
	pthread_mutex_destroy(&data.print_m);
	pthread_mutex_destroy(&data.dead_m);
}
