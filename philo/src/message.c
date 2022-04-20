/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 02:23:44 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/20 02:36:28 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, int msg_type)
{
	uint64_t	time;
	const char	*msg;
	static int	done = 0;

	pthread_mutex_lock(&philo->state->print_m);
	if (!done)
	{
		msg = get_message(msg_type);
		time = gettimenow() - philo->state->start_time;
		printf("%.5llu %d %s\n", time, philo->position, msg);
		if (msg_type == DEAD)
			done = 1;
		pthread_mutex_unlock(&philo->state->print_m);
	}
}

const char	*get_message(int message_type)
{
	if (message_type == FORK)
		return ("has taken a fork");
	if (message_type == EAT)
		return ("is eating");
	if (message_type == SLEEP)
		return ("is sleeping");
	if (message_type == THINK)
		return ("is thinking");
	return ("died");
}
