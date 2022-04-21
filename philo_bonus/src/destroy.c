/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:44:22 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/21 07:09:07 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	clear_data(t_data data)
{
	int		i;
	char	semaphore[50];

	if (data.philos)
	{
		i = 0;
		while (i < data.philo_count)
		{
			get_sem_name(SEM_EAT, semaphore, i);
			sem_unlink(semaphore);
			get_sem_name(SEM_PHILO, semaphore, i);
			sem_unlink(semaphore);
			i++;
		}
		free(data.philos);
	}
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_DEAD);
}
