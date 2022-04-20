/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:58:38 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/19 02:47:53 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks[philo->lfork]);
	print_msg(philo, FORK);
	pthread_mutex_lock(&philo->state->forks[philo->rfork]);
	print_msg(philo, FORK);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->state->forks[philo->lfork]);
	pthread_mutex_unlock(&philo->state->forks[philo->rfork]);
	print_msg(philo, SLEEP);
	usleep(philo->state->time_to_sleep * 1000);
}
