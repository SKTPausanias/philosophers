/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:00:16 by mlaplana          #+#    #+#             */
/*   Updated: 2020/02/25 16:55:20 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_print(char *str, t_philo *phil)
{
	pthread_mutex_lock(&phil->data->print);
	if (!phil->data->dead)
	{
		ft_putnbr(get_time());
		ft_putstr(" ");
		ft_putnbr(phil->num + 1);
		ft_putstr(" ");
		ft_putstr(str);
	}
	if (!ft_strcmp(str, "is dead\n"))
		phil->data->dead = 1;
	pthread_mutex_unlock(&phil->data->print);
}

void	ft_eat(t_philo *phil)
{
	pthread_mutex_lock(&phil->forks[phil->num]);
	ft_print("has taken a fork\n", phil);
	pthread_mutex_lock(&phil->forks[(phil->num + 1) % phil->data->phil_num]);
	ft_print("has taken a fork\n", phil);
	ft_print("is eating\n", phil);
	phil->start_eat_time = get_time();
	pthread_mutex_lock(&phil->deads[phil->num]);
	phil->last_time_eaten = get_time();
	usleep(phil->data->t_to_eat * 1000);
	phil->times_eaten++;
	pthread_mutex_unlock(&phil->forks[phil->num]);
	pthread_mutex_unlock(&phil->forks[(phil->num + 1) % phil->data->phil_num]);
	pthread_mutex_unlock(&phil->deads[phil->num]);
}

void	ft_is_dead(t_philo *phil)
{
	unsigned long time;

	phil->last_time_eaten = get_time();
	while (!phil->data->dead)
	{
		pthread_mutex_lock(&phil->deads[phil->num]);
		if (phil->data->times_of_eat != 0 &&
		phil->times_eaten == phil->data->times_of_eat)
			break ;
		time = get_time();
		if ((time - phil->last_time_eaten) >
		(unsigned long)phil->data->t_to_die)
		{
			ft_print("is dead\n", phil);
			break ;
		}
		pthread_mutex_unlock(&phil->deads[phil->num]);
		usleep(8 * 1000);
	}
	pthread_mutex_unlock(&phil->deads[phil->num]);
}

void	ft_do_something(t_philo *phil)
{
	while (!phil->data->dead)
	{
		ft_print("is thinking\n", phil);
		ft_eat(phil);
		if (phil->data->times_of_eat != 0 &&
		phil->times_eaten == phil->data->times_of_eat)
			break ;
		ft_print("is sleeping\n", phil);
		usleep(phil->data->t_to_sleep * 1000);
	}
}

int		main(int argc, char **av)
{
	int		i;
	t_data	data;

	if (ft_get_args(argc, av, &data) == 0)
		return (0);
	i = -1;
	ft_init(&data, i);
	return (0);
}
