/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 04:39:34 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 10:02:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	//fork then eat then sleep then think
	if (philo->id == 1)
	{
		if (!first_philo_cycle(philo))
			return (0);
	}
/*	else
	{
		if ()
			return (0);
	}
	if ()
		return (0);
	if ()
		return (0);*/
	return (1);
}

void	*loop(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	if (philo->data->nb_must_eat == 0)
		return (NULL);
/////////
	while (1)
	{
	//////////
		if (philo->data->nb_philo == 1)
			return (loop_alone(philo));
		if (!loop_start(philo))
			return (NULL);
	}
	return (NULL);
}
