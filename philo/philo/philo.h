/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrocher <mrocher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:24:22 by mrocher           #+#    #+#             */
/*   Updated: 2024/04/28 19:39:03 by mrocher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_program
{
	int				nbr_philo;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				eat_limits;
	int				end;
	int				finish_to_x;
	long int		start;
	pthread_mutex_t	mutex_lock;
	pthread_mutex_t	died;
	pthread_mutex_t	time_eat;
	pthread_mutex_t	finish;
}					t_program;

typedef struct s_philo
{
	int				id;
	int				finish;
	pthread_t		thread_id;
	pthread_t		death_id;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	left_fork;
	t_program		*program;
	unsigned int	nb_time_eat;
	long int		time_eat_milli;
}					t_philo;

typedef struct s_all
{
	t_philo		*philo;
	t_program	program;
}				t_all;

/* ARGV VALID*/
int			argv_valid(int ac, char **av);

/* INIT */
void		init_av(t_all *all, char **av);
int			init_all(t_all *all);

/* ROUTINE */
int			check_dead(t_philo *philo, int i);
int			check_dead2(t_all *all);
void		sleeping(t_philo *philo);
void		think(t_philo *philo);
void		routine(t_philo *philo);

/* STATUS */
void		print_status(char *str, t_philo *philo);
void		*philo_is_dead(void *ptr);
void		check_death_id(void	*ptr);
void		*thread_create(void *ptr);
int			thread_init(t_all *all);

/* UTILS */
int			ft_atoi(const char *s);
long int	get_time(void);
void		ft_usleep(long int milli);
void		clean_all(t_all *all);

#endif
