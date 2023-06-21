/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_act.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:10:10 by azari             #+#    #+#             */
/*   Updated: 2023/06/21 11:44:26 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_philosleep(unsigned long time)
{
	unsigned long	init;

	init = ft_gettime();
	while (1)
	{
		if (ft_gettime() - init >= time)
			break ;
		wusleep(50);
	}
}

bool	ft_philoeats(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->fork);
	ft_print_action(ACT_FORK, philo, 1);
	if (data->n_philos == 1)
	{
		ft_philosleep(data->tt_die);
		return (false);
	}
	sem_wait(data->fork);
	ft_print_action(ACT_FORK, philo, 1);
	ft_print_action(ACT_EAT, philo, 1);
	ft_philosleep(data->tt_eat);
	sem_post(data->fork);
	sem_post(data->fork);
	sem_wait(data->meal);
	philo->l_eat = ft_gettime();
	philo->n_meals++;
	sem_post(data->meal);
	return (true);
}
