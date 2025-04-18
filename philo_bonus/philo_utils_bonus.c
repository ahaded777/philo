#include "./philo_bonus.h"

void print_status(t_philo *philo, char *message)
{
    sem_wait(philo->data->print);
    printf("%ld %d %s", get_current_time(), philo->id, message);
    sem_post(philo->data->print);
}
