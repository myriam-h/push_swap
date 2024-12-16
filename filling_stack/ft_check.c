#include "../push_swap.h"

int ft_is_dup(int num, int pos, int *arr)
{
   while (pos >= 0)
    {
        if (arr[pos] == num)
            return 1;
        pos--;
    }
    return (0);
}

int ft_size(char **argv)
{
    int i = 0;
    while (argv[i])
        i++;
    return (i);
}

int ft_check(char **argv)
{
    int *arr;
    int i;
    int num;
    
    arr = (int *)malloc(sizeof(int) * (ft_size(argv)));
    if (!arr)
        return (1);
    i = 0;
    while (argv[i])
    {
        num = ft_atoi(argv[i]);
        if (!(num >= INT_MIN && num <= INT_MAX) || 
        ft_is_dup(num, i - 1, arr))
        {
            free(arr);
            return (1);
        }
        arr[i++] = num;
    }
    free(arr);
    return 0;
}