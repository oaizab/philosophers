/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:21:06 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/12 22:29:57 by oaizab           ###   ########.fr       */
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

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4
# define HUNGRY 5

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
	int				dead;
	int				state;
	time_t			last_eat;
	time_t			start_running; // TODO: time_t instead of uint64_t;
	pthread_mutex_t	fork;
	struct s_philo	*right;
}				t_philo;

int			is_args_error(t_args args);
t_args		ft_parser(int ac, char *av[]);
void		destroy_philos(t_philo **philos);
t_philo		*init_philos(t_args args);
void		*routine(void *arg);
time_t		gettimenow(void);
void		print_msg(t_philo *philo, const char *msg);
int			any_die(t_philo *philo);
int			is_alive(t_philo *philo);
int			take_forks(t_philo *philo);
int			eat(t_philo *philo);

#endif