#include "./philo_bonus.h"

void cleanup(t_data *data)
{
    sem_close(data->forks);
    sem_close(data->print);
    sem_close(data->simulation_over);
    sem_close(data->meal_lock);
    sem_close(data->meal_time);
    sem_unlink("/forks");
    sem_unlink("/print");
    sem_unlink("/simulation");
    sem_unlink("/meal_lock");
    sem_unlink("/meal_time");
    free(data->philo);
}
