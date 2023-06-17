/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:11:18 by azari             #+#    #+#             */
/*   Updated: 2023/06/17 14:54:44 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static char	*ft_strchr(const char *hay, int c)
{
	size_t	i;

	i = -1;
	while (hay[++i])
	{
		if (hay[i] == (char)c)
			return ((char *)&hay[i]);
	}
	return (0);
}

int	ft_str_isdigit(char *str)
{
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			str++;
		else
		 	return (0);
	}
	return (1);
}
int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_strchr(WHITESPACES, str[i]))
		i++;
	(ft_strchr("+-", str[i])) && (sign = '-' - str[i] - 1) && (i += 1);
	if (!ft_str_isdigit((char *)(str + i)) || sign < 0)
		return (-1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - 48;
		if (result > INT_MAX)
			return (-1);
	}
	return (result * sign);
}

int	ft_checkargs(char **av)
{
	int	i;

	i = 0;
	if (av[1] && !ft_atoi(av[1]))
		return (0);
	while (av[++i])
		if (ft_atoi(av[i]) <= 0)
			return (0);
	return (1);
}

int	ft_raise_exception(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (0);
}
