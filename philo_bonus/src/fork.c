/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:58:38 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/21 06:23:54 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	get_forks(t_philo *philo)
{
	sem_wait(philo->state->forks);
	print_msg(philo, FORK);
	sem_wait(philo->state->forks);
	print_msg(philo, FORK);
}

void	put_forks(t_philo *philo)
{
	sem_post(philo->state->forks);
	sem_post(philo->state->forks);
	print_msg(philo, SLEEP);
	usleep(philo->state->time_to_sleep * 1000);
}
