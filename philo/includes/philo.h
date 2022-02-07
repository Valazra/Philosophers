/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:23:58 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 14:33:22 by user42           ###   ########.fr       */
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

# define DIED 0
# define EAT 1
# define OTHER 2

typedef struct s_data
{
	int				nb_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				nb_must_eat;
	int				is_finish;
	int				finish_eat;
	long			time_start;
	pthread_mutex_t	write_mutex;
}		t_data;

typedef struct s_philo
{
	int				id;
	int				nb_eaten;
	long			save_time_eat;
	pthread_t		thread_id;
	pthread_t		thread_check_id;
	pthread_mutex_t	left_fork_mutex;
	pthread_mutex_t	*right_fork_mutex;
	t_data			*data;
}		t_philo;

int		init_and_check_params(int ac, char **av, t_data *data);
int		write_error(char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	init_structs(t_data *data, t_philo *philo);
int		create_threads(t_philo *philo);
int		finish_threads(t_philo *philo);
void	*loop(void *philo_arg);
long	ft_time(void);
void	use_usleep(long time_to_wait);
int		display_action(t_philo *philo, char *str, int statut);
int		insert_nb_in_str(long nb, char *str);
int		first_philo_cycle(t_philo *philo);
int		cycle_eat(t_philo *philo);
int		cycle_sleep(t_philo *philo);
int		cycle_think(t_philo *philo);

#endif
