/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 04:34:32 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 16:07:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	finish_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		if (pthread_join(philo[i].thread_id, NULL))
			return (write_error("Error with pthread_create."));
		i++;
	}
	use_usleep(philo->data->ttd * 2);
	pthread_mutex_lock(&philo->data->write_mutex);
	pthread_mutex_unlock(&philo->data->write_mutex);
	pthread_mutex_destroy(&philo->data->write_mutex);
	i = 0;
	while (i < philo->data->nb_philo)
	{
		pthread_mutex_destroy(&philo[i].left_fork_mutex);
		i++;
	}
	free(philo);
	return (1);
}

int	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_philo)
	{
		if (pthread_create(&philo[i].thread_id, NULL, &loop, &philo[i]))
			return (write_error("Error with pthread_create"));
		i++;
	}
	return (1);
}
