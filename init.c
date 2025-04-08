#include "philo.h"

void init_philosophers(t_data *data)
{
    int i;
    
    data->forks = malloc(sizeof(pthread_mutex_t) * data->count_philos);
    data->philo = malloc(sizeof(t_philo) * data->count_philos);
    data->monitor = malloc(sizeof(pthread_t));
    i = 0;
    while (i < data->count_philos)
        pthread_mutex_init(&data->forks[i++], NULL);
    i = 0;
    while (i < data->count_philos)
    {
        data->philo[i].id = i + 1;
        data->philo[i].last_meal_time = get_current_time();
        data->philo[i].count_eat = 0;
        data->philo[i].left_fork = &data->forks[i];
        data->philo[i].right_fork = &data->forks[(i + 1) % data->count_philos];
        data->philo[i].data = data;
        i++;
    }
}

void init_data(t_data *data, char **args)
{
    data->count_philos = ft_atoi(args[1]);
    data->time_to_die = ft_atoi(args[2]);
    data->time_to_eat = ft_atoi(args[3]);
    data->time_to_sleep = ft_atoi(args[4]);
    if (args[5])
        data->time_to_op = ft_atoi(args[5]);
    data->stop_simulation = 0;
    pthread_mutex_init(&data->writing, NULL);
    pthread_mutex_init(&data->meal, NULL);
}