/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:21:06 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/21 07:39:37 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/types.h>
# include <string.h>
# include <semaphore.h>
# include <signal.h>

# define SEM_PRINT "p_sem_print"
# define SEM_EAT "p_sem_eat"
# define SEM_FORK "p_sem_fork"
# define SEM_DEAD "p_sem_dead"
# define SEM_PHILO "p_sem_philo"

# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4
# define OVER 5
# define FORK 6

typedef struct s_args
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_eats;
}				t_args;

struct	s_data;

typedef struct s_philo
{
	pid_t			pid;
	int				position;
	int				is_eating;
	uint32_t		eat_count;
	uint64_t		limit;
	uint64_t		last_eat;
	struct s_data	*state;
	sem_t			*philo_s;
	sem_t			*eat_s;
}				t_philo;

typedef struct s_data
{
	int			philo_count;
	uint64_t	start_time;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	int			max_eat;
	t_philo		*philos;
	sem_t		*forks;
	sem_t		*print_s;
	sem_t		*dead_s;
}				t_data;

int			is_args_error(t_args args);
t_args		ft_parser(int ac, char *av[]);
void		clear_data(t_data data);
int			init_philos(t_data *data);
int			start_philos(t_data *data);
uint64_t	gettimenow(void);
void		print_msg(t_philo *philo, int msg_type);
const char	*get_message(int message_type);
void		get_forks(t_philo *philo);
void		eat(t_philo *philo);
void		put_forks(t_philo *philo);
void		*eat_count_c(void *data_v);
void		*alive_c(void *philo_v);
int			init(t_data *data, t_args args);
int			check(int argc, char*argv[], t_args *args);
int			exit_error(const char *msg);
int			routine(t_philo *philo);
void		get_sem_name(const char *sem_type, char semaphore[], int sem_nb);
sem_t		*ft_sem_open(const char *sem, int value);

#endif