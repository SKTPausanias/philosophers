/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:24:54 by mlaplana          #+#    #+#             */
/*   Updated: 2020/03/01 14:25:18 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/sem.h>
# include <sys/stat.h>
# include <signal.h>

typedef struct		s_data
{
	int				phil_num;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				times_of_eat;
	int				dead;
	pid_t			wpid;
}					t_data;

typedef struct		s_philo
{
	int				num;
	unsigned long	last_time_eaten;
	int				times_eaten;
	t_data			*data;
	sem_t			*forks;
	sem_t			*deads;
	sem_t			*prints;
	pid_t			pid;
}					t_philo;

int					ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);
int					ft_atoi(const char *str);
int					ft_perror(char *str);
unsigned long		get_time(void);
int					ft_strcmp(char *s1, char *s2);
void				ft_putstr(char *str);
void				ft_putnbr(unsigned long num);
sem_t				*ft_sem_open(char *str, int value);
int					ft_get_args(int argc, char **av, t_data *data);
void				ft_waiting(t_data *data, t_philo *phil, int i);
int					ft_start_threads(t_data *data, int i, t_philo *phil);
void				ft_init(t_data *data, int i);
void				ft_print(char *str, t_philo *phil);
void				ft_eat(t_philo *phil);
void				ft_is_dead(t_philo *phil);
void				ft_do_something(t_philo *phil);
#endif
