/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:42:53 by aahaded           #+#    #+#             */
/*   Updated: 2025/04/18 18:42:54 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_current_time(void)
{
	struct timeval	time;
	static size_t	start_time;
	size_t			timer;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "philo: gettimeofday() error\n", 22);
	timer = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (start_time == 0)
		start_time = timer;
	return (timer - start_time);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(100);
	return (0);
}
