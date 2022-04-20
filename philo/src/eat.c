/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:03:37 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/20 01:24:27 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo->is_eating = 1;
	philo->last_eat = gettimenow();
	print_msg(philo, EAT);
	philo->limit = philo->last_eat + philo->state->time_to_die;
	usleep(philo->state->time_to_eat * 1000);
	philo->eat_count++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->eat_m);
}
