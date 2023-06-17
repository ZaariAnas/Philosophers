/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:31:13 by azari             #+#    #+#             */
/*   Updated: 2023/06/17 15:42:39 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	**ft_philoinit(t_data *data)
{
	t_philo	**philos;
	int		i;

	i = -1;
	philos = malloc(sizeof(t_philo) * data->n_philos);
	if (!philos)
		return (free(data->fork), free(data), ft_error(ALLOC_ERR), NULL);
	while (++i < data->n_philos)
	{
		philos[i]->p_id = i;
		philos[i]->n_meals = 0;
		philos[i]->data = data;
	}
	return (philos);
}

pthread_mutex_t	*ft_mutexinit(t_data *data)
{
	pthread_mutex_t	*forks;
	int	nphilo;
	int	i;

	i = -1;
	nphilo = data->n_philos;
	forks = malloc(sizeof(pthread_mutex_t) * nphilo);
	while (++i < nphilo)
		pthread_mutex_init(&forks[i], NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->meal, NULL);
	return (forks);
}

void	ft_datainit(t_data *data, char **av)
{
	data->start_t = ft_gettime();
	data->n_philos = ft_atoi(av[1]);
	data->fork = ft_mutexinit(data);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	(av[5]) && (data->max_meals = ft_atoi(av[5]));
	(!data->max_meals) && (data->max_meals = -1);
}
