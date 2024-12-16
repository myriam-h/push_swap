#include "../push_swap.h"

int ft_strlen(const char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

char *ft_strjoin(const char *s1, const char *s2)
{
    int i;
    char *result;

    if (!s1 || !s2)
        return (NULL);
    result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
    if (!result)
        return (NULL);                                                               
    i = 0;
    while (*s1)
        result[i++] = *s1++;
    while (*s2)
        result[i++] = *s2++;
    result[i] = ' ';
    result[++i] = '\0';
    return (result);
}