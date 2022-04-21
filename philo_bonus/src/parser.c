/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaizab <oaizab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:02:40 by oaizab            #+#    #+#             */
/*   Updated: 2022/04/21 07:02:43 by oaizab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi_p(const char *nbr_str)
{
	long	nb;
	int		i;

	i = 0;
	nb = 0;
	while (nbr_str[i])
	{
		if ((nbr_str[i] >= '0' && nbr_str[i] <= '9'))
			nb = nb * 10 + (nbr_str[i++] - '0');
		else
			return (-1);
	}
	return (nb);
}

t_args	args_error(void)
{
	t_args	args;

	args.number_of_philos = -1;
	args.time_to_die = -1;
	args.time_to_eat = -1;
	args.time_to_sleep = -1;
	args.number_of_eats = -1;
	return (args);
}

int	is_args_error(t_args args)
{
	if (args.number_of_philos == -1)
		return (1);
	if (args.time_to_die == -1)
		return (1);
	if (args.time_to_eat == -1)
		return (1);
	if (args.time_to_sleep == -1)
		return (1);
	return (0);
}

t_args	ft_parser(int ac, char *av[])
{
	t_args	args;
	int		t[6];
	int		i;

	if (ac == 5 || ac == 6)
	{
		i = 1;
		t[5] = -1;
		while (i < ac)
		{
			t[i] = ft_atoi_p(av[i]);
			if (t[i] == -1)
				return (args_error());
			i++;
		}
		args.number_of_philos = t[1];
		args.time_to_die = t[2];
		args.time_to_eat = t[3];
		args.time_to_sleep = t[4];
		args.number_of_eats = t[5];
	}
	else
		args = args_error();
	return (args);
}
