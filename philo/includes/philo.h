/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 07:23:58 by user42            #+#    #+#             */
/*   Updated: 2022/02/05 08:15:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct	s_data
{
	int	nb_philo;
	int	ttd;
	int	tte;
	int	tts;
	int	nb_must_eat;
}		t_data;

typedef struct	s_philo
{
	int	id;
	t_data	*data;
}		t_philo;

int	init_and_check_params(int ac, char **av, t_data *data);
int	write_error(char *str);
int	ft_strlen(char *str);


#endif
