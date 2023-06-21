/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:19:16 by azari             #+#    #+#             */
/*   Updated: 2023/06/21 11:35:10 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

unsigned int	ft_gettime(void)
{
	struct timeval	t;

	if (gettimeofday(&t, NULL))
		return (0);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_print_action(char *action, t_philo *philo, int unlock)
{
	unsigned long	ms;

	sem_wait(philo->data->print);
	ms = ft_gettime() - philo->data->start_t;
	printf("%lu %d %s\n", ms, philo->phid + 1, action);
	if (unlock)
		sem_post(philo->data->print);
}

void	wusleep(int us)
{
	int	i;

	i = -1;
	while (++i < us)
		usleep(1);
}
