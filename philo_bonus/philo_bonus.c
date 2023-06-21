/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:17:49 by azari             #+#    #+#             */
/*   Updated: 2023/06/21 11:54:06 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	**philos;

	if (ac == 5 || ac == 6)
	{
		if (!ft_checkargs(av))
			return (ft_raise_exception(ARG_ERR));
		data = malloc(sizeof(t_data));
		if (!data)
			return (ft_raise_exception(ALLOC_ERR));
		ft_datainit(data, av);
		ft_seminit(data);
		philos = ft_philoinit(data);
		ft_run(philos);
		waitpid(-1, NULL, 0);
		ft_end(philos);
	}
	else
		return (ft_raise_exception(ARG_NUM_ERR));
}
