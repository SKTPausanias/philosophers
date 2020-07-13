/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:03:31 by mlaplana          #+#    #+#             */
/*   Updated: 2020/03/06 17:03:33 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

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

int		ft_start_threads(t_data *data, int i, t_philo *phil)
{
	pthread_t	philo[data->phil_num];
	pthread_t	dead[data->phil_num];
	int			err;

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

void	ft_init(t_data *data, int i)
{
	t_philo	phil[data->phil_num];
	sem_t	*forksem;
	sem_t	*prints;
	char	*aux;
	char	*temp;

	forksem = ft_sem_open("FORKS_SEM", data->phil_num);
	prints = ft_sem_open("PRINT_SEM", 1);
	while (++i < data->phil_num)
	{
		phil[i].data = data;
		temp = malloc(sizeof(2));
		temp[0] = i + '0';
		temp[1] = '\0';
		aux = ft_strjoin("/sem", temp);
		phil[i].deads = ft_sem_open(aux, 1);
		free(temp);
		free(aux);
		phil[i].forks = forksem;
		phil[i].prints = prints;
		phil[i].times_eaten = 0;
	}
	ft_start_threads(data, -1, phil);
}
