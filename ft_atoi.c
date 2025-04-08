#include "./philo.h"

int ft_atoi(char *str)
{
    int i;
    int s;
    long r;

    i = 0;
    s = 1;
    r = 0;
    while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            s = s * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        r = (r * 10) + (str[i] - '0');
        if (r > 2147483647 || r < -2147483648)
            return (-1);
        i++;
    }
    return (s * r);
}