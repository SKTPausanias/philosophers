/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaplana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:32:44 by mlaplana          #+#    #+#             */
/*   Updated: 2020/03/06 17:32:46 by mlaplana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		ft_strcmp(char *s1, char *s2)
{
	unsigned char		*str1;
	unsigned char		*str2;
	unsigned int		i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] == str2[i] && str1[i] && s2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(unsigned long num)
{
	char *base;

	base = "0123456789";
	if (num >= 10)
		ft_putnbr(num / 10);
	write(1, &base[num % 10], 1);
}

sem_t	*ft_sem_open(char *str, int value)
{
	sem_unlink(str);
	return (sem_open(str, O_CREAT | O_EXCL, 0666, value));
}
