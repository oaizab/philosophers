/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:24:23 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/11 12:02:43 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(int argc, char *argv[])
{
	t_args		args;
	t_philo		*philos;
	int			i;
	pthread_t	*th;

	args = ft_parser(argc, argv);
	if (is_args_error(args))
	{
		printf("Error Arguments\n");
		return (0);
	}
	philos = init_philos(args);
	if (!philos)
		return (0);
	th = NULL;
	th = malloc(sizeof(pthread_t) * args.number_of_philos);
	if (!th)
		return (0);
	i = 1;
	pthread_create(&th[0], NULL, routine, philos);
	while (i < args.number_of_philos)
	{
		philos = philos->right;
		pthread_create(&th[i], NULL, routine, philos);
		i++;
	}
	i = 0;
	while (i < args.number_of_philos)
	{
		philos = philos->right;
		pthread_join(th[i], NULL);
		i++;
	}
	destroy_philos(&philos);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	ret;

	ret = start(argc, argv);
	// (void) argc;
	// (void) argv;
	// ret = 0;
	// uint64_t t1 = gettimenow();
	// usleep(100000);
	// uint64_t t2 = gettimenow();
	// printf("%lld\n%lld\n", t1, t2);
	// printf("%.10lld\n", t2 - t1);
	return (ret);
}
