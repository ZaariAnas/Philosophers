/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_thread.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:53:58 by azari             #+#    #+#             */
/*   Updated: 2023/06/21 11:52:47 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*ft_routine(void *p)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)p;
	if (philo->phid % 2)
		wusleep(100);
	while (1)
	{
		ft_philoeats(philo);
		if (philo->data->n_philos == 1)
			break ;
		ft_print_action(ACT_SLEEP, philo, 1);
		ft_philosleep(philo->data->tt_sleep);
		ft_print_action(ACT_THINK, philo, 1);
	}
	return (NULL);
}

void	ft_deathchecker(t_philo *p)
{
	while (1)
	{
		sem_wait(p->data->meal);
		if (ft_gettime() - p->l_eat >= (unsigned long)p->data->tt_die)
			return (ft_print_action(ACT_DEAD, p, 0));
		if (p->data->max_meals != -1 && (p->data->max_meals) < p->n_meals)
			return ;
		sem_post(p->data->meal);
	}
}

void	ft_run(t_philo **philos)
{
	int	i;

	i = -1;
	philos[0]->data->start_t = ft_gettime();
	while (++i < philos[0]->data->n_philos)
	{
		philos[i]->pid = fork();
		if (philos[i]->pid == 0)
		{
			philos[i]->l_eat = ft_gettime();
			if (pthread_create(&philos[i]->tid, NULL, &ft_routine, philos[i]))
				return ((void)ft_raise_exception(THRD_CREAT_ERR));
			if (pthread_detach(philos[i]->tid))
				return ((void)ft_raise_exception(THRD_DTCH_ERR));
			ft_deathchecker(philos[i]);
			exit(0);
		}
	}
}

void	ft_end(t_philo **philos)
{
	int		i;
	t_data	*data;

	i = -1;
	data = philos[0]->data;
	while (++i < data->n_philos)
		kill(philos[i]->pid, SIGKILL);
	sem_unlink(FORKS);
	sem_unlink(MEALS);
	sem_unlink(PRINT);
	i = -1;
	while (++i < data->n_philos)
		free(philos[i]);
	sem_close(data->fork);
	sem_close(data->meal);
	sem_close(data->print);
	free(data);
	free(philos);
}
