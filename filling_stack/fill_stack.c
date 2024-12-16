#include "../push_swap.h"

void clean_stack(stack_node **sa)
{
    stack_node *current;
    stack_node *next;

    current = *sa;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *sa = NULL;
}

stack_node *get_last_node(stack_node *sa)
{
    stack_node *last_node;
    
    last_node = sa;
    while (last_node && last_node->next)
        last_node = last_node->next;
    return (last_node);
}

int add_node(stack_node **sa, int num)
{
    stack_node *new_node;
    stack_node *last_node;
    
    new_node = (stack_node *)malloc(sizeof(stack_node));
    if (!new_node)
        return 1;
    new_node->next = NULL;
    new_node->data = num;
    if (*sa == NULL)
    {
        *sa = new_node;
        new_node->prev = NULL;
    }
    else
    {
        last_node = get_last_node(*sa);
        last_node->next = new_node;
        new_node->prev = last_node;
    }
    return 0;
}

void fill_stack(stack_node **sa, char **argv)
{
    int i;
    int value;
    
    if (sa == NULL || ft_check(argv))
    {
        clean_array(argv);
        prog_exit(false, sa);
    }
        
    i = 0;
    while (argv[i])
    {
        value = ft_atoi(argv[i]);
        if (add_node(sa, value))
        {
            clean_array(argv);
            prog_exit(true, sa);
        }
        i++;
    }
}