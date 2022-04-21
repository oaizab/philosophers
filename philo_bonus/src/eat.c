/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:03:37 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/21 06:22:12 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat(t_philo *philo)
{
	sem_wait(philo->philo_s);
	philo->is_eating = 1;
	philo->last_eat = gettimenow();
	print_msg(philo, EAT);
	philo->limit = philo->last_eat + philo->state->time_to_die;
	usleep(philo->state->time_to_eat * 1000);
	philo->eat_count++;
	philo->is_eating = 0;
	sem_post(philo->philo_s);
	sem_post(philo->eat_s);
}
