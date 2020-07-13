/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:23:31 by mlaplana          #+#    #+#             */
/*   Updated: 2020/03/06 16:23:32 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		ft_get_args(int argc, char **av, t_data *data)
{
	if (argc < 5 || argc > 6)
	{
		write(1, "Invalid number of arguments\n", 28);
		return (0);
	}
	if ((data->phil_num = ft_atoi(av[1])) <= 0)
		return (ft_perror("Invalid Argument\n"));
	if ((data->t_to_die = ft_atoi(av[2])) < 0)
		return (ft_perror("Invalid Argument\n"));
	if ((data->t_to_eat = ft_atoi(av[3])) < 0)
		return (ft_perror("Invalid Argument\n"));
	if ((data->t_to_sleep = ft_atoi(av[4])) < 0)
		return (ft_perror("Invalid Argument\n"));
	if (argc == 6)
	{
		if ((data->times_of_eat = ft_atoi(av[5])) < 0)
			return (ft_perror("Invalid Argument\n"));
	}
	else
		data->times_of_eat = 0;
	return (1);
}

void	ft_putnbr(unsigned long num)
{
	char *base;

	base = "0123456789";
	if (num >= 10)
		ft_putnbr(num / 10);
	write(1, &base[num % 10], 1);
}

int		ft_start_threads(t_philo *phil, t_data *data,
pthread_t *philo, pthread_t *dead)
{
	int i;
	int err;

	i = -1;
	while (++i < data->phil_num)
	{
		phil[i].num = i;
		if ((err = pthread_create(&philo[i], NULL,
		(void *)ft_do_something, &phil[i])) != 0)
			return (ft_perror(("Can not create a thread\n")));
		if ((err = pthread_create(&dead[i], NULL,
		(void *)ft_is_dead, &phil[i])) != 0)
			return (ft_perror(("Can not create a thread\n")));
		usleep(100);
	}
	i = -1;
	while (++i < data->phil_num)
		pthread_join(philo[i], NULL);
	i = -1;
	while (++i < data->phil_num)
		pthread_join(dead[i], NULL);
	return (0);
}

int		ft_start_mutex(t_philo *phil, t_data *data,
pthread_mutex_t *forks, pthread_mutex_t *deads)
{
	int i;
	int err;

	i = -1;
	while (++i < data->phil_num)
	{
		if ((err = pthread_mutex_init(&forks[i], NULL)) != 0)
			return (ft_perror("Can't initialize mutex\n"));
		if ((err = pthread_mutex_init(&deads[i], NULL)) != 0)
			return (ft_perror("Can't initialize mutex\n"));
	}
	if ((err = pthread_mutex_init(&phil->data->print, NULL)) != 0)
		return (ft_perror("Can't initialize mutex\n"));
	return (0);
}

void	ft_init(t_data *data, int i)
{
	t_philo			phil[data->phil_num];
	pthread_mutex_t	forks[data->phil_num];
	pthread_mutex_t	deads[data->phil_num];
	pthread_t		philo[data->phil_num];
	pthread_t		dead[data->phil_num];

	data->dead = 0;
	while (++i < data->phil_num)
	{
		phil[i].data = data;
		phil[i].forks = forks;
		phil[i].deads = deads;
		phil[i].times_eaten = 0;
	}
	ft_start_mutex(phil, data, forks, deads);
	ft_start_threads(phil, data, philo, dead);
}
