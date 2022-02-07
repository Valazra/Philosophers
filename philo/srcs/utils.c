/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 08:06:07 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 08:29:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	count_digits(long nb)
{
	int	ret;

	ret = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		ret++;
	}
	return (ret);
}

int	insert_nb_in_str(long nb, char *str)
{
	int	nb_digits;
	int	index;

	nb_digits = count_digits(nb);
	str[nb_digits] = ' ';
	index = nb_digits;
	while (--nb_digits > -1)
	{
		str[nb_digits] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (index);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
