/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 08:11:28 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 09:53:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_structs(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	data->is_finish = 0;
	data->finish_eat = 0;
	data->time_start = ft_time();
	pthread_mutex_init(&data->write_mutex, NULL);
	while (i < data->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].nb_eaten = 0;
		philo[i].save_time_eat = data->time_start;
		philo[i].right_fork_mutex = NULL;
		pthread_mutex_init(&philo[i].left_fork_mutex, NULL);
		if (data->nb_philo == 1)
			return ;
		if (data->nb_philo - 1 != i)
			philo[i].right_fork_mutex = &philo[i + 1].left_fork_mutex;
		if (data->nb_philo - 1 == i)
			philo[i].right_fork_mutex = &philo[0].left_fork_mutex;
		i++;
	}
}

int	init_data(t_data *data, char *str, int i)
{
	int		j;
	long	res;

	j = 0;
	res = 0;
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			return (0);
		res = (res * 10) + (str[j] - '0');
		j++;
	}
	if (res > 2147483647 || (res == 0 && i != 5))
		return (0);
	if (i == 1)
		data->nb_philo = res;
	if (i == 2)
		data->ttd = res;
	if (i == 3)
		data->tte = res;
	if (i == 4)
		data->tts = res;
	if (i == 5)
		data->nb_must_eat = res;
	return (1);
}

int	init_and_check_params(int ac, char **av, t_data *data)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (write_error("Bad number of params\n"));
	while (i < ac)
	{
		if (!init_data(data, av[i], i))
			return (write_error("Bad params\n"));
		i++;
	}
	return (1);
}
