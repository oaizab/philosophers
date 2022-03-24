/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:44:22 by oaizab            #+#    #+#             */
/*   Updated: 2022/03/24 19:14:26 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philos(t_philo **philos)
{
	t_philo	*iter;

	iter = *philos;
	while (iter->right != *philos)
		iter = iter->right;
	iter->right = NULL;
	while (*philos)
	{
		iter = *philos;
		*philos = (*philos)->right;
		pthread_mutex_destroy(&iter->fork);
		free(iter);
	}
}
