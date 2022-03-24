/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:24:23 by oaizab            #+#    #+#             */
/*   Updated: 2022/03/24 19:18:30 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_args	args;

	args = ft_parser(argc, argv);
	if (is_args_error(args))
	{
		printf("Error Arguments\n");
		return (0);
	}
	printf("Good arguments\n");
	return (0);
}
