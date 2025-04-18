#include "./philo_bonus.h"

void    kill_childs(t_data *data)
{
    int i;

    i = 0;
    while (i < data->count_philos)
    {
        kill(data->philo[i].pid, SIGKILL);
        i++;
    }
}
void *monitor_self(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        // if (philo->data->time_to_op && philo->count_eat >= philo->data->time_to_op)
        // {
        //     cleanup(philo->data);
        //     exit(0);
        // }
        sem_wait(philo->data->meal_time);
        if ((get_current_time() - philo->last_meal_time) > (size_t)philo->data->time_to_die)
        {
            sem_post(philo->data->meal_time);
            sem_wait(philo->data->print);
            printf("%ld %d died\n", get_current_time(), philo->id);
            exit(0);
        }
        sem_post(philo->data->meal_time);
        // ft_usleep(1000);
    }
    return (NULL);
}


void start_simulation(t_philo *philo)
{
    pthread_create(&philo->data->monitor, NULL, monitor_self, philo);
    // pthread_detach(philo->data->monitor);
    // if (philo->id % 2 == 0)
    //     ft_usleep(50);
    while (1)
    {
        if (philo->id % 2 == 0)
			usleep(200);
		if (philo->data->count_philos < 100)
			usleep(300);
        sem_wait(philo->data->forks);
        print_status(philo, "has taken a fork\n");
        sem_wait(philo->data->forks);
        print_status(philo, "has taken a fork\n");
        sem_wait(philo->data->meal_time);
        philo->last_meal_time = get_current_time();
        sem_post(philo->data->meal_time);
        print_status(philo, "is eating\n");
        philo->count_eat++;
        ft_usleep(philo->data->time_to_eat);
        sem_post(philo->data->forks);
        sem_post(philo->data->forks);
        if (philo->data->time_to_op && philo->count_eat >= philo->data->time_to_op)
        {
            cleanup(philo->data);
            exit(0);
        }
        print_status(philo, "is sleeping\n");
        ft_usleep(philo->data->time_to_sleep);
        print_status(philo, "is thinking\n");
    }
}

void fork_philosophers(t_data *data)
{
    int i;
    int status;
    
    i = 0;
    while (i < data->count_philos)
    {
        data->philo[i].pid = fork();
        if (data->philo[i].pid < 0)
        {
            perror("fork");
            cleanup(data);
            exit(1);
        }
        else if (data->philo[i].pid == 0)
        {
            start_simulation(&data->philo[i]);
            exit(0);
        }
        i++;
    }
    wait(&status);
    kill_childs(data);
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
    fork_philosophers(&data);
    cleanup(&data);
    return (0);
}
