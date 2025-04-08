#include "philo.h"

void *philosopher_routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        ft_usleep(50);
    while (!philo->data->stop_simulation)
    {
        pthread_mutex_lock(philo->left_fork);
        print_status(philo, "has taken a fork\n");
        if (philo->left_fork == philo->right_fork)
            break ;
        pthread_mutex_lock(philo->right_fork);
        print_status(philo, "has taken a fork\n");
        philo->last_meal_time = get_current_time();
        print_status(philo, "is eating\n");
        philo->count_eat++;
        ft_usleep(philo->data->time_to_eat);
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        print_status(philo, "is sleeping\n");
        ft_usleep(philo->data->time_to_sleep);
        print_status(philo, "is thinking\n");
    }
    return (NULL);
}

int verify_all_philosophers_eaten(t_data *data)
{
    int i;
    int num;

    i = 0;
    num = 0;
    if (data->time_to_op)
    {
        while (i < data->count_philos)
        {
            if (data->philo[i].count_eat == data->time_to_op)
                num += data->time_to_op;
            i++;
        }
        if (num == (data->time_to_op * data->count_philos))
            return (1);
    }
    return (0);
}

void *monitor_routine(void *arg)
{
    t_data *data;
    
    data = (t_data *)arg;
    while (!data->stop_simulation)
    {
        if (check_philo_status(data))
            break ;
        if (verify_all_philosophers_eaten(data))
        {
            data->stop_simulation = 1;
            break ;
        }
    }
    return (NULL);
}

void start_simulation(t_data *data)
{
    int i;
    pthread_t *threads;

    i = 0;
    threads = malloc(sizeof(pthread_t) * data->count_philos);
    pthread_create(data->monitor, NULL, monitor_routine, data);
    while (i < data->count_philos)
    {
        pthread_create(&threads[i], NULL, philosopher_routine, &data->philo[i]);
        i++;
    }
    pthread_join(*data->monitor, NULL);
    i = 0;
    while (i < data->count_philos)
        pthread_join(threads[i++], NULL);
    free(threads);
}

int main(int ac, char **av)
{
    t_data data;
    
    if (ac < 5 || ac > 6)
    {
        ft_putstr_fd("Usage: ./philo number_of_philosophers ", 2);
        ft_putstr_fd("time_to_die time_to_eat time_to_sleep ", 2);
        ft_putstr_fd("[number_of_times_each_philosopher_must_eat]\n", 2);
        return (1);
    }
    if (check_valid_args(av))
        return (1);
    init_data(&data, av);
    init_philosophers(&data);
    start_simulation(&data);
    cleanup(&data);
    return (0);
}