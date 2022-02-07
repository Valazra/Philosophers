/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 04:39:34 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 08:09:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*loop_alone(t_philo *philo)
{
	(void)philo;
	return (NULL);
}

int	loop_start(t_philo *philo)
{
	//fork then eat then sleep then think
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
