/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:42:23 by azari             #+#    #+#             */
/*   Updated: 2023/06/17 20:57:11 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ARG_NUM_ERR "\033[0;31merror :: unvalid number of arguments.\n"
# define THRD_CREAT_ERR "\033[0;31merror :: thread creation failure.\n"
# define THRD_DTCH_ERR "\033[0;31merror :: thread detaching failure.\n"
# define ALLOC_ERR "\033[0;31merror :: memory allocation failure. \n"
# define ARG_ERR "\033[0;31merror :: unvalid arguments.\n"
# define WHITESPACES " \t\r\v\n"

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int				max_meals;
	int				tt_sleep;
	int				n_philos;
	unsigned long	start_t;
	int				tt_eat;
	int				tt_die;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	meal;
}t_data;

typedef  struct	s_philo
{
	int				n_meals;
	t_data 			*data;
	unsigned int	l_eat;
	int				p_id;
	pthread_t		t_id;
}t_philo;


void			ft_datainit(t_data *data, char **av);
int				ft_error(char *str);
t_philo			**ft_philoinit(t_data *data);
int				ft_atoi(const char *str);
int				ft_checkargs(char **av);
unsigned int	ft_gettime(void);

#endif