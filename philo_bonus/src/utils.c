/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:20:12 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/21 07:39:59 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

uint64_t	gettimenow(void)
{
	struct timeval	tv;
	uint64_t		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	get_sem_name(const char *sem_type, char semaphore[], int sem_nb)
{
	int	i;

	i = 0;
	while (sem_type[i])
	{
		semaphore[i] = sem_type[i];
		i++;
	}
	while (sem_nb != 0)
	{
		semaphore[i++] = (sem_nb % 10) + '0';
		sem_nb /= 10;
	}
	semaphore[i] = '\0';
}

sem_t	*ft_sem_open(const char *sem, int value)
{
	return (sem_open(sem, O_CREAT | O_EXCL, 0644, value));
}
