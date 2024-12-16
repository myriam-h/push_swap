#include "../push_swap.h"

int ft_atoi(char *str)
{
    int sign = 1;
    int result = 0;

    while (*str == 32 || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (*str == '-' || *str == '+')
        return 0;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + *str - '0';
        str++;
    }
    return (result * sign);
}