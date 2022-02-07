/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 04:39:34 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 07:40:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*loop_alone(t_philo *philo)
{
	(void)philo;
	printf("yoyoyo\n");
	return (NULL);
}

void	*loop(void *philo_arg)
{
	t_philo	*philo;

	philo = (t_philo *)philo_arg;
	if (philo->data->nb_must_eat == 0)
		return (NULL);
	printf("bonjour\n");
/////////
	while (1)
	{
	//////////
		if (philo->data->nb_philo == 1)
			return (loop_alone(philo));
	// a remplir car si on a pas un seul philo ça fait boucle infinie	
	/////////
	}
	return (NULL);
}
