/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 11:55:30 by mlaplana          #+#    #+#             */
/*   Updated: 2020/02/27 11:55:35 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_print(char *str, t_philo *phil)
{
	sem_wait(phil->prints);
	if (!phil->data->dead)
	{
		ft_putnbr(get_time());
		ft_putstr(" ");
		ft_putnbr(phil->num);
		ft_putstr(" ");
		ft_putstr(str);
	}
	if (!ft_strcmp(str, "is dead\n"))
		phil->data->dead = 1;
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
	unsigned long time;

	phil->last_time_eaten = get_time();
	while (!phil->data->dead)
	{
		sem_wait(phil->deads);
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
		sem_post(phil->deads);
		usleep(8 * 1000);
	}
	sem_post(phil->deads);
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
	data.dead = 0;
	ft_init(&data, i);
	return (0);
}
