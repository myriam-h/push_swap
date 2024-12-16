#include "../push_swap.h"

stack_node *find_last_node(stack_node *stack)
{
    stack_node *last_node;

    while (stack)
    {
        last_node = stack;
        stack = stack->next;
    }
    return (last_node);
}

stack_node *find_minimum(stack_node *stack)
{
    stack_node *minimum;

    minimum = stack;
    while (stack)
    {
        if (stack->data < minimum->data)
            minimum = stack;
        stack = stack->next;
    }
    return (minimum);
}

stack_node *find_maximum(stack_node *stack)
{
    stack_node *maximum;

    maximum = stack;
    while (stack)
    {
        if (stack->data > maximum->data)
            maximum = stack;
        stack = stack->next;
    }
    return (maximum);
}

int stack_in_ascend(stack_node *sa)
{
     while (sa && sa->next)
     {
        if (sa->data > sa->next->data)
            return 0;
        sa = sa->next;
    }
    return (1);
}

int stack_size(stack_node *sa)
{
    int count;

    count = 0;
    while (sa)
    {
        count++;
        sa = sa->next;
    }
    return (count);
}