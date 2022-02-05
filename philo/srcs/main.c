/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:25:24 by user42            #+#    #+#             */
/*   Updated: 2022/02/05 07:59:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char *str, int i)
{
	int	j;
	long	res;

	j = 0;
	res = 0;
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			return (0);
		res = res * 10 + str[j] - '0';
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

int	init_params(int ac, char **av, t_data *data)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (write_error("Bad number of params"));
	while (i < ac)
	{
		if (!init_data(data, av[i], i))
			return (write_error("Bad params"));
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	data.nb_must_eat = -1;
	if (!init_params(ac, av, &data))
		return (-1);
	return (0);
}
