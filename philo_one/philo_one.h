/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:59:51 by mlaplana          #+#    #+#             */
/*   Updated: 2020/02/25 16:13:15 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct		s_data
{
	int				phil_num;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				times_of_eat;
	int				dead;
	pthread_mutex_t print;
}					t_data;

typedef struct		s_philo
{
	int				num;
	unsigned long	start_eat_time;
	unsigned long	last_time_eaten;
	int				times_eaten;
	t_data			*data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*deads;
}					t_philo;

int					ft_atoi(const char *str);
int					ft_perror(char *str);
unsigned long		get_time();
int					ft_strcmp(char *s1, char *s2);
void				ft_putstr(char *str);
int					ft_get_args(int argc, char **av, t_data *data);
void				ft_putnbr(unsigned long num);
int					ft_start_threads(t_philo *phil, t_data *data,
pthread_t *philo, pthread_t *dead);
int					ft_start_mutex(t_philo *phil, t_data *data,
pthread_mutex_t *forks, pthread_mutex_t *deads);
void				ft_init(t_data *data, int i);
void				ft_do_something(t_philo *phil);
void				ft_is_dead(t_philo *phil);
void				ft_eat(t_philo *phil);
void				ft_print(char *str, t_philo *phil);
#endif
