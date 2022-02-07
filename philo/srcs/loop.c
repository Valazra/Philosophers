/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 04:39:34 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 23:46:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*loop_check_death(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	use_usleep(philo->data->ttd + 1);
	pthread_mutex_lock(&philo->data->write_mutex);
	if (((ft_time() - philo->save_time_eat) >= philo->data->ttd)
		&& !philo->data->is_finish)
	{
		philo->data->is_finish = 1;
		display_action(philo, "died", DIED);
		return (NULL);
	}
	pthread_mutex_unlock(&philo->data->write_mutex);
	return (NULL);
}

void	*loop_alone(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork_mutex);
	if (!display_action(philo, "has taken a fork", OTHER))
	{
		pthread_mutex_unlock(&philo->left_fork_mutex);
		return (NULL);
	}
	use_usleep(philo->data->ttd);
	pthread_mutex_unlock(&philo->left_fork_mutex);
	return (NULL);
}

int	loop_start(t_philo *philo)
{
	if (philo->id == 1)
	{
		if (!first_philo_cycle(philo))
			return (0);
	}
	if (philo->id != 1)
	{
		if (!cycle_eat(philo))
			return (0);
	}
	if (!cycle_sleep(philo))
		return (0);
	if (!cycle_think(philo))
		return (0);
	return (1);
}

void	*loop(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	if (philo->data->nb_must_eat == 0)
		return (NULL);
	if (philo->id % 2 == 0)
		use_usleep(philo->data->tte / 10);
	while (1)
	{
		if (pthread_create(&philo->thread_check_id, NULL,
				&loop_check_death, philo_arg))
		{
			philo->data->is_finish = 3;
			write_error("Error with pthread_create\n");
			return (NULL);
		}
		pthread_detach(philo->thread_check_id);
		if (philo->data->nb_philo == 1)
			return (loop_alone(philo));
		if (!loop_start(philo))
			return (NULL);
	}
	return (NULL);
}
