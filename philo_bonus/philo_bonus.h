/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azari <azari@student.1337.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:19:48 by azari             #+#    #+#             */
/*   Updated: 2023/06/21 11:36:30 by azari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define WHITESPACES " \t\r\v\n"
# define ARG_NUM_ERR "\033[0;31merror :: unvalid number of arguments.\n"
# define THRD_CREAT_ERR "\033[0;31merror :: thread creation failure.\n"
# define THRD_DTCH_ERR "\033[0;31merror :: thread detaching failure.\n"
# define ALLOC_ERR "\033[0;31merror :: memory allocation failure. \n"
# define ARG_ERR "\033[0;31merror :: unvalid arguments.\n"
# define ACT_FORK "has taken a fork"
# define ACT_SLEEP "is sleeping"
# define ACT_THINK "is thinking"
# define ACT_EAT "is eating"
# define ACT_DEAD "died"
# define FORKS "/forks"
# define MEALS "/meals"
# define PRINT "/print"

# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_data {
	int				max_meals;
	int				tt_sleep;
	int				n_philos;
	unsigned long	start_t;
	int				tt_eat;
	int				tt_die;
	sem_t			*print;
	sem_t			*fork;
	sem_t			*meal;
}t_data;

typedef struct s_philo {
	int				n_meals;
	t_data			*data;
	unsigned int	l_eat;
	int				phid;
	pthread_t		tid;
	pid_t			pid;
}t_philo;

void			ft_print_action(char *action, t_philo *philo, int unlock);
void			ft_datainit(t_data *data, char **av);
void			ft_philosleep(unsigned long time);
int				ft_raise_exception(char *str);
t_philo			**ft_philoinit(t_data *data);
bool			ft_philoeats(t_philo *philo);
void			ft_seminit(t_data *data);
int				ft_atoi(const char *str);
void			ft_run(t_philo **philos);
void			ft_end(t_philo **philos);
int				ft_checkargs(char **av);
unsigned int	ft_gettime(void);
void			wusleep(int us);
int				ft_process(t_philo *philo);

#endif