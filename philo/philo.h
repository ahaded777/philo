/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:46:18 by aahaded           #+#    #+#             */
/*   Updated: 2025/04/18 18:46:19 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	size_t				last_meal_time;
	int					count_eat;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					count_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_op;
	int					stop_simulation;
	int					i;
	pthread_mutex_t		*forks;
	pthread_t			*monitor;
	pthread_mutex_t		meal;
	pthread_mutex_t		writing;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		last_meal;
	pthread_mutex_t		died_mutex;
	t_philo				*philo;
}						t_data;

int						ft_atoi(char *str);
int						ft_isdigit(int c);
void					ft_putstr_fd(char *s, int fd);
size_t					get_current_time(void);
int						ft_usleep(size_t milliseconds);
void					init_data(t_data *data, char **args);
void					cleanup(t_data *data);
void					init_philosophers(t_data *data);
void					print_status(t_philo *philo, char *message);
int						check_philo_status(t_data *data);
void					*philosopher_routine(void *arg);
void					*monitor_routine(void *arg);
void					start_simulation(t_data *data);
int						check_valid_args(char **args);
void					ft_putchar_fd(char c, int fd);

#endif
