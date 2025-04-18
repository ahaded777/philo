/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:42:30 by aahaded           #+#    #+#             */
/*   Updated: 2025/04/18 18:42:33 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->writing);
	if (!philo->data->stop_simulation)
		printf("%zu %d %s", get_current_time(), philo->id, message);
	pthread_mutex_unlock(&philo->data->writing);
}

int	check_philo_status(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->count_philos)
	{
		pthread_mutex_lock(&data->meal);
		if ((get_current_time()
				- data->philo[i].last_meal_time) > (size_t)data->time_to_die)
		{
			print_status(&data->philo[i], "died\n");
			data->stop_simulation = 1;
			pthread_mutex_unlock(&data->meal);
			return (1);
		}
		pthread_mutex_unlock(&data->meal);
		i++;
	}
	return (0);
}
