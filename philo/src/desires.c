/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desires.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:21:24 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/12 22:33:28 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (any_die(philo))
		return (0);
	philo->state = EATING;
	pthread_mutex_lock(&philo->fork);
	print_msg(philo, "has taken fork");
	while (philo->right->state == EATING && !any_die(philo));
	if (!is_alive(philo))
		return (0);
	if (philo->state == DEAD || any_die(philo))
	{
		pthread_mutex_unlock(&philo->fork);
		return (0);
	}
	pthread_mutex_lock(&philo->right->fork);
	print_msg(philo, "has taken fork");
	return (1);
}

int	eat(t_philo *philo)
{
	time_t	time;

	if (!is_alive(philo))
		return (pthread_mutex_unlock(&philo->right->fork), 0);
	if (any_die(philo))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->right->fork);
		return (0);
	}
	time = gettimenow();
	// printf("%ld - %ld = %d\n", time, philo->last_eat, (int) (time - philo->last_eat));
	philo->last_eat = time;
	print_msg(philo, "is eating");
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->right->fork);
	philo->state = SLEEPING;
	return (1);
}
