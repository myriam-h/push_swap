#include "push_swap.h"

void clean_array(char **argv)
{
    int i;                                   
                                           
    i = 0;                                
    while (argv[i])                        
    {                            
        free(argv[i]);                     
        i++;
    }
    free(argv);
}

void prog_exit(bool clean, stack_node **sa)
{
    if (clean)
        clean_stack(sa);
    else
        ft_printf("ERROR\n");
    exit(1);
}

char **one_arg(char **argv, stack_node **sa)
{
    int i;
    char *tempo;
    char *tempo_n;

    tempo = (char *)malloc(sizeof(char) * 1);
    if (!tempo)
        prog_exit(false, sa);
    i = 1;
    tempo[0] = '\0';
    while (argv[i])
    {
        tempo_n = ft_strjoin(tempo, argv[i]);
        free (tempo);
        if (!tempo_n)
            prog_exit(false, sa);
        tempo = tempo_n;
        i++;
    }
    argv = ft_split(tempo);
    free (tempo);
    return (argv);
}

int main(int argc, char *argv[])
{
    stack_node *sa;
    stack_node *sb;

    sa = NULL;
    sb = NULL;
    if (argc < 2 || (argc == 2 && !argv[1][0]))
        exit(1);
    else if (argc == 2)
        argv = ft_split(argv[1]);
    else
        argv = one_arg(argv, &sa);
    if (!argv)
        prog_exit(false, &sa);
    fill_stack(&sa, argv);
    clean_array(argv);
    push_swap(&sa, &sb);
    clean_stack(&sa);
    return 0;
}