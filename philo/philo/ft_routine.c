/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:58:51 by mrocher           #+#    #+#             */
/*   Updated: 2024/04/21 21:31:52 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo, int i)
{
	int	end_value;

	pthread_mutex_lock(&philo->program->died);
	if (i)
		philo->program->end = i;
	end_value = philo->program->end;
	pthread_mutex_unlock(&philo->program->died);
	return (end_value);
}

int	check_dead2(t_all *all)
{
	int	result;

	pthread_mutex_lock(&all->program.died);
	result = all->program.end;
	pthread_mutex_unlock(&all->program.died);
	return (result);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->program->mutex_lock);
	print_status("is sleeping\n", philo);
	pthread_mutex_unlock(&philo->program->mutex_lock);
}

void	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->program->mutex_lock);
	print_status("is thinking\n", philo);
	pthread_mutex_unlock(&philo->program->mutex_lock);
}

void	routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	pthread_mutex_lock(&philo->program->mutex_lock);
	print_status("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->program->mutex_lock);
	if (!philo->right_fork)
	{
		ft_usleep(philo->program->time_to_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->program->mutex_lock);
	print_status("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->program->mutex_lock);
	pthread_mutex_lock(&philo->program->mutex_lock);
	print_status("is eating\n", philo);
	pthread_mutex_lock(&philo->program->time_eat);
	philo->time_eat_milli = get_time();
	pthread_mutex_unlock(&philo->program->time_eat);
	pthread_mutex_unlock(&philo->program->mutex_lock);
	ft_usleep(philo->program->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
	sleeping(philo);
	ft_usleep(philo->program->time_to_sleep);
	think(philo);
}
