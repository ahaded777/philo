#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_data t_data;

typedef struct s_philo
{
    int             id;
    pid_t           pid;
    size_t          last_meal_time;
    int             count_eat;
    t_data          *data;
} t_philo;

typedef struct s_data
{
    int             count_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             time_to_op;
    int             stop_simulation;
    size_t          start_time;
    sem_t           *forks;
    sem_t           *print;
    sem_t           *simulation_over;
    sem_t           *meal_lock;
    sem_t           *meal_time;
    pthread_t       monitor;
    t_philo         *philo;
} t_data;

int     ft_atoi(char *str);
int     ft_isdigit(int c);
void    ft_putstr_fd(char *s, int fd);
size_t  get_current_time(void);
void     ft_usleep(size_t milliseconds);
void    init_data(t_data *data, char **args);
void    cleanup(t_data *data);
void    init_philosophers(t_data *data);
void    print_status(t_philo *philo, char *message);
int     check_valid_args(char **args);
void    start_simulation(t_philo *philo);
void	ft_putchar_fd(char c, int fd);

#endif