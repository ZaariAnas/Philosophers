/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:41:41 by azari             #+#    #+#             */
/*   Updated: 2023/06/17 20:01:01 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_data	*data;
	t_philo	**philos;

	if (ac == 5 || ac == 6)
	{
		if (!ft_checkargs(av))
			return (ft_error(ARG_ERR));
		data = malloc(sizeof(t_data));
		if (!data)
			return (ft_error(ALLOC_ERR));
		ft_datainit(data, av);
		philos = ft_philoinit(data);
		if (!philos)
			return (ft_error(ALLOC_ERR));
		ft_run(philos);
	}
	else
		return (ft_error(ARG_NUM_ERR));
}
