/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:23:44 by mrocher           #+#    #+#             */
/*   Updated: 2024/04/26 18:20:16 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	argv_number(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_number(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	argv_valid(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("Argv is incorrect: [number_of_philosophers]"
			"[time_to_die] [time_to_eat] "
			"[time_to_sleep] (number_of_times_each_philosopher_must_eat)\n");
		return (1);
	}
	if (argv_number(ac, av))
	{
		printf("Argv is incorrect: caracters detected\n");
		return (1);
	}
	return (0);
}
