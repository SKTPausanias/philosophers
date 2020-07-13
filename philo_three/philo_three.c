/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:23:51 by mlaplana          #+#    #+#             */
/*   Updated: 2020/03/01 14:24:03 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_print(char *str, t_philo *phil)
{
	sem_wait(phil->prints);
	ft_putnbr(get_time());
	ft_putstr(" ");
	ft_putnbr(phil->num);
	ft_putstr(" ");
	ft_putstr(str);
	if (!ft_strcmp(str, "is dead\n"))
		phil->data->dead = 1;
	else
		sem_post(phil->prints);
}

void	ft_eat(t_philo *phil)
{
	sem_wait(phil->forks);
	ft_print("has taken a fork\n", phil);
	sem_wait(phil->forks);
	ft_print("has taken a fork\n", phil);
	ft_print("is eating\n", phil);
	sem_wait(phil->deads);
	phil->last_time_eaten = get_time();
	usleep(phil->data->t_to_eat * 1000);
	phil->times_eaten++;
	sem_post(phil->forks);
	sem_post(phil->forks);
	sem_post(phil->deads);
}

void	ft_is_dead(t_philo *phil)
{
	phil->last_time_eaten = get_time();
	while (1)
	{
		sem_wait(phil->deads);
		if ((get_time() - phil->last_time_eaten) >
		(unsigned long)phil->data->t_to_die)
		{
			ft_print("is dead\n", phil);
			exit(0);
		}
		sem_post(phil->deads);
		usleep(8000);
	}
}

void	ft_do_something(t_philo *phil)
{
	while (1)
	{
		ft_print("is thinking\n", phil);
		ft_eat(phil);
		if (phil->data->times_of_eat != 0 &&
		phil->times_eaten == phil->data->times_of_eat)
			break ;
		ft_print("is sleeping\n", phil);
		usleep(phil->data->t_to_sleep * 1000);
	}
	exit(0);
}

int		main(int argc, char **av)
{
	int		i;
	t_data	data;

	if (ft_get_args(argc, av, &data) == 0)
		return (0);
	i = -1;
	data.dead = 0;
	ft_init(&data, i);
	return (0);
}
