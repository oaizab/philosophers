/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:20:12 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/12 22:09:21 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	gettimenow(void)
{
	struct timeval	tv;
	time_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	print_msg(t_philo *philo, const char *msg)
{
	time_t	time;

	time = gettimenow() - philo->start_running;
	printf("%.10ld %d %s\n", time, philo->philo_number, msg);
}

int	is_alive(t_philo *philo)
{
	time_t	time;

	time = gettimenow();
	if ((int) (time - philo->last_eat) > philo->time_to_die)
	{
		print_msg(philo, "died");
		philo->state = DEAD;
		pthread_mutex_unlock(&philo->fork);
		// pthread_mutex_unlock(&philo->right->fork);
		return (0);
	}
	return (1);
}

int	any_die(t_philo *philo)
{
	t_philo *iter;

	iter = philo->right;
	while (iter != philo)
	{
		if (iter->state == DEAD)
			return (1);
		iter = iter->right;
	}
	return (iter->state == DEAD);
}
