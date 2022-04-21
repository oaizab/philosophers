/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:57:58 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/21 07:13:23 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	static t_data	data;
	t_args			args;
	int				i;

	if (check(argc, argv, &args))
		return (exit_error("Error Arguments"));
	if (init(&data, args))
		return (clear_data(data), exit_error("Error init"));
	if (start_philos(&data))
		return (clear_data(data), exit_error("Error starting philos"));
	sem_wait(data.dead_s);
	i = 0;
	while (i < data.philo_count)
		kill(data.philos[i++].pid, SIGKILL);
	clear_data(data);
	return (0);
}
