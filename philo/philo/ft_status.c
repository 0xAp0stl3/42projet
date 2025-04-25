/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:12:33 by mrocher           #+#    #+#             */
/*   Updated: 2024/04/28 19:40:45 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *str, t_philo *philo)
{
	long int	time;

	time = -1;
	time = get_time() - philo->program->start;
	if (time >= 0 && time <= 2147483647 && !check_dead(philo, 0))
	{
		printf("%ld ", time);
		printf("%d %s", philo->id, str);
	}
}

void	*philo_is_dead(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	ft_usleep(philo->program->time_to_die + 1);
	pthread_mutex_lock(&philo->program->finish);
	if (!check_dead(philo, 0) && !philo->finish)
	{
		pthread_mutex_unlock(&philo->program->finish);
		pthread_mutex_lock(&philo->program->time_eat);
		if ((get_time() - philo->time_eat_milli) \
			>= (long)(philo->program->time_to_die))
		{
			pthread_mutex_unlock(&philo->program->time_eat);
			pthread_mutex_lock(&philo->program->mutex_lock);
			print_status("died\n", philo);
			pthread_mutex_unlock(&philo->program->mutex_lock);
			check_dead(philo, 1);
		}
		else
			pthread_mutex_unlock(&philo->program->time_eat);
	}
	else
		pthread_mutex_unlock(&philo->program->finish);
	return (NULL);
}

void	check_death_id(void	*ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	pthread_create(&philo->death_id, NULL, philo_is_dead, ptr);
	pthread_detach(philo->death_id);
}

void	*thread_create(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(philo->program->time_to_eat / 10);
	check_death_id(ptr);
	while (!check_dead(philo, 0))
	{
		routine(philo);
		if ((int)++philo->nb_time_eat == philo->program->eat_limits)
		{
			pthread_mutex_lock(&philo->program->finish);
			philo->finish = 1;
			philo->program->finish_to_x++;
			if (philo->program->finish_to_x == philo->program->nbr_philo)
			{
				pthread_mutex_unlock(&philo->program->finish);
				check_dead(philo, 2);
			}
			else
				pthread_mutex_unlock(&philo->program->finish);
			return (NULL);
		}
	}
	return (NULL);
}

int	thread_init(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->program.nbr_philo)
	{
		all->philo[i].program = &all->program;
		if (pthread_create(&all->philo[i].thread_id, NULL, \
			thread_create, &all->philo[i]) != 0)
		{
			printf("Pthread did not return \n");
			return (0);
		}
		i++;
	}
	return (1);
}
