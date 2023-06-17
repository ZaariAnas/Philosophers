/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:07:12 by azari             #+#    #+#             */
/*   Updated: 2023/06/17 15:17:24 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

unsigned int	ft_gettime(void)
{
	struct timeval t;

	if (gettimeofday(&t, NULL))
		return (0);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}
