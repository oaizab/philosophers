/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:17:40 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/20 02:41:44 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo_v)
{
	t_philo		*philo;
	pthread_t	th;

	philo = philo_v;
	philo->last_eat = gettimenow();
	philo->limit = philo->last_eat + philo->state->time_to_die;
	if (pthread_create(&th, NULL, alive_c, philo_v) != 0)
		return (NULL);
	pthread_detach(th);
	while (philo->eat_count < (unsigned int) philo->state->max_eat)
	{
		get_forks(philo);
		eat(philo);
		put_forks(philo);
		print_msg(philo, THINK);
	}
	return (NULL);
}
