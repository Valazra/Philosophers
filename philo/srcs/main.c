/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:25:24 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 09:04:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	data.nb_must_eat = -1;
	if (init_and_check_params(ac, av, &data) == -1)
		return (-1);
	philo = malloc(sizeof(*philo) * data.nb_philo);
	if (!philo)
		return (write_error("Malloc_error"));
	memset(philo, 0, sizeof(t_philo) * data.nb_philo);
	init_structs(&data, philo);
	create_threads(philo);
	finish_threads(philo);
	return (0);
}
