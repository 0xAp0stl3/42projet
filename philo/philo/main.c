/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:25:55 by mrocher           #+#    #+#             */
/*   Updated: 2024/04/26 18:13:09 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_all	all;

	if (argv_valid(ac, av))
		return (1);
	init_av(&all, av);
	if (!init_all(&all) || !thread_init(&all))
	{
		free(all.philo);
		return (0);
	}
	clean_all(&all);
	return (0);
}
