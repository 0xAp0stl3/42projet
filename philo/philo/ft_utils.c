/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:00:21 by mrocher           #+#    #+#             */
/*   Updated: 2024/04/26 18:38:13 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *s)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((s[i] > 8 && s[i] < 14) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result > INT_MAX / 10 \
			|| (result == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10))
			exit(EXIT_FAILURE);
		result = result * 10 + s[i] - '0';
		i++;
	}
	return (result * sign);
}

long int	get_time(void)
{
	long int		current;
	struct timeval	time;

	current = 0;
	if (gettimeofday(&time, NULL) == -1)
		printf("Fonctions get_time error\n");
	current = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current);
}

void	ft_usleep(long int milli)
{
	long int	time;

	time = 0;
	time = get_time();
	while ((get_time() - time) < milli)
		usleep(milli / 10);
}

void	clean_all(t_all *all)
{
	int	i;

	i = -1;
	while (!check_dead2(all))
		ft_usleep(1000);
	while (++i < all->program.nbr_philo)
	{
		pthread_join(all->philo[i].thread_id, NULL);
		pthread_mutex_destroy(&all->philo[i].left_fork);
	}
	pthread_mutex_destroy(&all->program.mutex_lock);
	if (all->philo)
		free(all->philo);
}
