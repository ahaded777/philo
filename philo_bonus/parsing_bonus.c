#include "./philo_bonus.h"

int is_valid_number(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (!ft_isdigit(arg[i]))
            return (1);
        i++;
    }
    return (0);
}

int check_valid_args_utils(char **args)
{
    if ((ft_atoi(args[3]) < 0 || ft_atoi(args[3]) > 2147483647) || is_valid_number(args[3]))
    {
        ft_putstr_fd("philo: Invalid time to eat\n", 2);
        return (1);
    }
    else if ((ft_atoi(args[4]) < 0 || ft_atoi(args[4]) > 2147483647) || is_valid_number(args[4]))
    {
        ft_putstr_fd("philo: Invalid time to sleep\n", 2);
        return (1);
    }
    else if (args[5] && ((ft_atoi(args[5]) < 0 || ft_atoi(args[5]) > 2147483647) || is_valid_number(args[5])))
    {
        ft_putstr_fd("philo: Invalid number of times each philosopher must eat\n", 2);
        return (1);
    }
    return (0);
}

int check_valid_args(char **args)
{
    if (ft_atoi(args[1]) == 0 || (args[5] && ft_atoi(args[5]) == 0))
        return (1);
    if ((ft_atoi(args[1]) < 0 || ft_atoi(args[1]) > 200) || is_valid_number(args[1]))
    {
        ft_putstr_fd("philo: Invalid philosophers number\n", 2);
        return (1);
    }
    else if ((ft_atoi(args[2]) < 0 || ft_atoi(args[2]) > 2147483647) || is_valid_number(args[2]))
    {
        ft_putstr_fd("philo: Invalid time to die\n", 2);
        return (1);
    }
    else
        return (check_valid_args_utils(args));
}
