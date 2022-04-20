/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:57:58 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/20 02:41:12 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	static t_data	data;
	t_args			args;

	if (check(argc, argv, &args))
		return (exit_error("Error Arguments"));
	if (init(&data, args))
		return (clear_data(data), exit_error("Error init"));
	if (start_philos(&data))
		return (clear_data(data), exit_error("Error starting philos"));
	pthread_mutex_lock(&data.dead_m);
	pthread_mutex_unlock(&data.dead_m);
	clear_data(data);
}
