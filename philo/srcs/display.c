/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 08:09:53 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 09:20:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	other(t_philo *philo, char buff[100])
{
	if (philo->data->is_finish)
	{
		pthread_mutex_unlock(&philo->data->write_mutex);
		return (0);
	}
	ft_putstr(buff);
	pthread_mutex_unlock(&philo->data->write_mutex);
	return (1);
}

int	eat(t_philo *philo, char buff[100])
{
	if (philo->data->is_finish)
	{
		pthread_mutex_unlock(&philo->data->write_mutex);
		return (0);
	}
	ft_putstr(buff);
////////////////
	return (1);
}

int	die(t_philo *philo, char buff[100])
{
	ft_putstr(buff);
	pthread_mutex_unlock(&philo->data->write_mutex);
	return (1);
}

int	display_action(t_philo *philo, char *str, int statut)
{
	char	buff[100];
	int		i;
	int		index;
	long		time_elapsed;

	index = 0;
	i = -1;
	memset(buff, 0, 100);
	if (statut != DIED)
		pthread_mutex_lock(&philo->data->write_mutex);
	time_elapsed = ft_time() - philo->data->time_start;
	index = insert_nb_in_str(time_elapsed, buff) + 1;
	index += insert_nb_in_str((long)philo->id, &buff[index]) + 1;
	while (str[++i])
		buff[index + i] = str[i];
	index = index + i;
	buff[index] = '\n';
	buff[index + 1] = '\0';
	if (statut == EAT)
		return (eat(philo, buff));
	if (statut == OTHER)
		return (other(philo, buff));
	return (die(philo, buff));
}
