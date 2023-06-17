/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:23:06 by azari             #+#    #+#             */
/*   Updated: 2023/06/17 21:02:59 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_routine(void *);
void	*ft_deathChecker(void *);

void	ft_run(t_philo **philos, int nph)
{
	int	i;
		
	i = -1;
	while (++i < nph)
	{
		philos[i]->l_eat = ft_gettime();
		if (pthread_create(&philos[i]->t_id, NULL, &ft_routine, NULL))
			return ((void)ft_error(THRD_CREAT_ERR));
	}
	i = -1;
	while (++i < nph)
		if (pthread_detach(philos[i]->t_id))
			ft_error(THRD_DTCH_ERR);
	ft_deathChecker(philos);
}
