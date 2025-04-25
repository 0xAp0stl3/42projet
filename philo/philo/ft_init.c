/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:14:21 by mrocher           #+#    #+#             */
/*   Updated: 2024/04/26 18:46:59 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_av(t_all *all, char **av)
{
	all->program.nbr_philo = ft_atoi(av[1]);
	all->program.time_to_die = ft_atoi(av[2]);
	all->program.time_to_eat = ft_atoi(av[3]);
	all->program.time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		all->program.eat_limits = ft_atoi(av[5]);
	else
		all->program.eat_limits = -1;
	if (all->program.nbr_philo == 0 || all->program.time_to_die == 0
		|| all->program.time_to_eat == 0 || all->program.time_to_sleep == 0)
		exit(EXIT_FAILURE);
	if (all->program.nbr_philo > 500)
		exit(EXIT_FAILURE);
	all->philo = malloc(sizeof(t_philo) * all->program.nbr_philo);
	if (!all->philo)
		return ;
}

void	init_mutex(t_all *all)
{
	pthread_mutex_init(&all->program.mutex_lock, NULL);
	pthread_mutex_init(&all->program.died, NULL);
	pthread_mutex_init(&all->program.time_eat, NULL);
	pthread_mutex_init(&all->program.finish, NULL);
}

int	init_all(t_all *all)
{
	int	i;

	i = 0;
	all->program.start = get_time();
	all->program.end = 0;
	all->program.finish_to_x = 0;
	init_mutex(all);
	while (i < all->program.nbr_philo)
	{
		all->philo[i].id = i + 1;
		all->philo[i].time_eat_milli = all->program.start;
		all->philo[i].nb_time_eat = 0;
		all->philo[i].finish = 0;
		all->philo[i].right_fork = NULL;
		pthread_mutex_init(&all->philo[i].left_fork, NULL);
		if (all->program.nbr_philo == 1)
			return (1);
		if (i == all->program.nbr_philo - 1)
			all->philo[i].right_fork = &all->philo[0].left_fork;
		else
			all->philo[i].right_fork = &all->philo[i + 1].left_fork;
		i++;
	}
	return (1);
}
