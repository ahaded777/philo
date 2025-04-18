/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:41:11 by aahaded           #+#    #+#             */
/*   Updated: 2025/04/18 18:41:12 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (i < data->count_philos)
			pthread_mutex_destroy(&data->forks[i++]);
		free(data->forks);
	}
	if (data->philo)
		free(data->philo);
	pthread_mutex_destroy(&data->writing);
	pthread_mutex_destroy(&data->meal);
	if (data->monitor)
		free(data->monitor);
}
