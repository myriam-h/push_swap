#include "../push_swap.h"

void ft_clean(char **arr, int i)
{
    i--;
    while (i >= 0 )
    {
        free (arr[i]);
        i--;
    }
    free (arr);
}

int ft_isspace(char c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}

int count_words(const char *str)
{
    int count; 
    
    count = 0;
    while (*str)
    {
        while (*str && ft_isspace(*str))
            str++;
        if (*str && !ft_isspace(*str))
            count++;
        while (*str && !ft_isspace(*str))
            str++;
    }
    return (count);
}

char *malloc_number(const char *str)
{
    int i;
    int j;
    char *numb;

    i = 0;
    j = 0;
    while (str[i] && !ft_isspace(str[i]))
        i++;
    numb = (char *)malloc(sizeof(char) * (i + 1));
    if (!numb)
        return (NULL);                                       
    i = 0;
    if (str[i] == '+' || str[i] == '-')
        numb[j++] = str[i++];
    while (str[i] && !ft_isspace(str[i]))
    {
        if (str[i] >= '0' && str[i] <= '9')
            numb[j++] = str[i++];
        else
        {
            free(numb);
            return (NULL);                                   
        }
    }
    numb[i] = '\0';
    return (numb);
}

char **ft_split(const char *str)
{
    int  i;
    char **arr;

    arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
    if (!arr || !str)
        return (NULL);
    i = 0;
    while (*str)
    {
        while (*str && ft_isspace(*str))
            str++;
        if (*str && !ft_isspace(*str))
        {
            arr[i] = malloc_number(str);
            if (arr[i] == NULL)
            {
                ft_clean(arr, i);
                return (NULL);                                
            }
            i++;
        }
        while (*str && !ft_isspace(*str))
            str++;
    }
    arr[i] = NULL;
    return (arr);
}