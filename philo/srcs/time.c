/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:25:55 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 09:00:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	use_usleep(long time_to_wait)
{
	long	call_time;

	call_time = 0;
	call_time = ft_time();
	while ((ft_time() - call_time) < time_to_wait)
		usleep(100);
}

long	ft_time(void)
{
	long			time;
	struct timeval	tv;

	time = 0;
	if (gettimeofday(&tv, NULL) == -1)
		return (write_error("Error with gettimeofday()"));
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}
