/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:23:58 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 05:31:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_data
{
	int	nb_philo;
	int	ttd;
	int	tte;
	int	tts;
	int	nb_must_eat;
	//int	is_finish;
	//int	finish_eat;
	long	time_start;
	//pthread_mutex_t	write_mutex;
}		t_data;

typedef struct s_philo
{
	int		id;
	//int		nb_time_eat;
	//long		record_time_eat;
	pthread_t	thread_id;
	//pthread_t	thread_check_id;
	pthread_mutex_t	left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	//pthread_mutex_t	time_mutex;
	t_data	*data;
}		t_philo;

int		init_and_check_params(int ac, char **av, t_data *data);
int		write_error(char *str);
int		ft_strlen(char *str);
void	init_structs(t_data *data, t_philo *philo);
int		create_threads(t_philo *philo);
void	finish_threads(t_philo *philo);
void	*routine(void *void_p);
long	ft_time(void);

#endif
