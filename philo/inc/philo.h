/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:21:06 by oaizab            #+#    #+#             */
/*   Updated: 2022/03/24 19:16:28 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <string.h>

typedef struct s_args
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_eats;
}				t_args;

typedef struct s_philo
{
	int				philo_number;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eats;
	uint64_t		last_eat;
	pthread_mutex_t	fork;
	struct s_philo	*right;
}				t_philo;

int		is_args_error(t_args args);
t_args	ft_parser(int ac, char *av[]);
void	destroy_philos(t_philo **philos);
t_philo	*init_philos(t_args args);

#endif