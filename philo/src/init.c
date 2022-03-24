/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:29:03 by oaizab            #+#    #+#             */
/*   Updated: 2022/03/24 19:16:42 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*fill_philo(t_args args, int i)
{
	t_philo	*philo;

	philo = malloc(sizeof(philo));
	if (!philo)
		return (NULL);
	if (pthread_mutex_init(&philo->fork, NULL))
		return (free(philo), NULL);
	philo->philo_number = i;
	philo->time_to_die = args.time_to_die;
	philo->time_to_die = args.time_to_die;
	philo->time_to_sleep = args.time_to_sleep;
	philo->number_of_eats = args.number_of_eats;
	philo->last_eat = -1;
	philo->right = NULL;
	return (philo);
}

t_philo	*init_philos(t_args args)
{
	int		i;
	t_philo	*head;
	t_philo	*tail;

	i = 1;
	head = fill_philo(args, 0);
	if (!head)
		return (NULL);
	tail = head;
	while (i < args.number_of_philos)
	{
		tail->right = fill_philo(args, i);
		if (!tail->right)
		{
			tail->right = head;
			return (destroy_philos(&head), NULL);
		}
		tail = tail->right;
		i++;
	}
	tail->right = head;
	return (head);
}