/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:57:14 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 10:03:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	first_philo_cycle(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork_mutex);
	if (!display_action(philo, "has taken a fork", 2))
	{
		pthread_mutex_unlock(&philo->left_fork_mutex);
		return (0);
	}
	pthread_mutex_lock(philo->right_fork_mutex);
	if (!display_action(philo, "has taken a fork", 2))
	{
		pthread_mutex_unlock(&philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
		return (0);
	}
	if (!display_action(philo, "is eating", 1))
	{
		pthread_mutex_unlock(&philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
		return (0);
	}
	use_usleep(philo->data->tte);
	pthread_mutex_unlock(&philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	return (1);
}