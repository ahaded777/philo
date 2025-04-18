#include "./philo_bonus.h"

void init_philosophers(t_data *data)
{
    int i;
    
    sem_unlink("/forks");
    sem_unlink("/print");
    sem_unlink("/simulation");
    sem_unlink("/meal_lock");
    sem_unlink("/meal_time");
    data->forks = sem_open("/forks", O_CREAT, 0644, data->count_philos);
    data->print = sem_open("/print", O_CREAT, 0644, 1);
    data->simulation_over = sem_open("/simulation", O_CREAT, 0644, 1);
    data->meal_lock = sem_open("/meal_lock", O_CREAT, 0644, 1);
    data->meal_time = sem_open("/meal_time", O_CREAT, 0644, 1);
    data->start_time = get_current_time();
    data->philo = malloc(sizeof(t_philo) * data->count_philos);
    i = 0;
    while (i < data->count_philos)
    {
        data->philo[i].id = i + 1;
        data->philo[i].pid = 0;
        data->philo[i].last_meal_time = get_current_time();
        data->philo[i].count_eat = 0;
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
    else
        data->time_to_op = 0;
    data->stop_simulation = 0;
}