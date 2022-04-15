/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:17:40 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/12 22:32:27 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	// time_t	time;

	philo = (t_philo *) arg;
	while (philo->number_of_eats != 0 && !any_die(philo))
	{
		philo->state = THINKING;
		print_msg(philo, "is thinking");
		// pthread_mutex_lock(&philo->fork);
		// print_msg(philo, "has taken fork");
		// if (!is_alive(philo))
		// 	break ;
		// pthread_mutex_lock(&philo->right->fork);
		// print_msg(philo, "has taken fork");
		// if (!is_alive(philo))
		// 	break ;
		if (!take_forks(philo))
			break ;
		// time = gettimenow();
		// // printf("%ld - %ld = %d\n", time, philo->last_eat, (int) (time - philo->last_eat));
		// philo->last_eat = time;
		// print_msg(philo, "is eating");
		// usleep(philo->time_to_eat * 1000);
		// pthread_mutex_unlock(&philo->fork);
		// pthread_mutex_unlock(&philo->right->fork);
		// philo->state = SLEEPING;
		if (!eat(philo))
			break ;
		philo->number_of_eats--;
		if (philo->number_of_eats == 0)
			break ;
		print_msg(philo, "is sleeping");
		usleep(philo->time_to_sleep * 1000);
	}
	return (NULL);
}
