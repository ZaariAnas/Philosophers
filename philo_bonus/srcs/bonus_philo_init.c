/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:09:33 by azari             #+#    #+#             */
/*   Updated: 2023/06/21 11:36:51 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_seminit(t_data *data)
{
	sem_unlink(FORKS);
	sem_unlink(MEALS);
	sem_unlink(PRINT);
	data->fork = sem_open(FORKS, O_CREAT, 0600, data->n_philos);
	data->meal = sem_open(MEALS, O_CREAT, 0600, 1);
	data->print = sem_open(PRINT, O_CREAT, 0600, 1);
}

void	ft_datainit(t_data *data, char **av)
{
	data->n_philos = ft_atoi(av[1]);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	data->max_meals = -1;
	(av[5] != NULL) && (data->max_meals = ft_atoi(av[5]));
}

t_philo	**ft_philoinit(t_data *data)
{
	t_philo	**philos;
	int		i;

	i = -1;
	philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!philos)
		return (free(data), ft_raise_exception(ALLOC_ERR), NULL);
	while (++i < data->n_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		philos[i]->phid = i;
		philos[i]->n_meals = 0;
		philos[i]->data = data;
	}
	return (philos);
}
