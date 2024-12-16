#include "../push_swap.h"

void push_b(stack_node **sa, stack_node **sb)
{
    stack_node *head;

    head = *sb;
    if ((*sb)->next)
    {
        *sb = (*sb)->next;
        (*sb)->prev = NULL;
    }
    else
        *sb = NULL;
    (*sa)->prev = head;
    head->next = *sa;
    head->prev = NULL;
    (*sa) = head;
    ft_printf("pa\n");
}

void push(stack_node **sa, stack_node **sb, int n)
{
    stack_node *head;

    if (n == 1)
    {
        head = *sa;
        *sa = (*sa)->next;
        (*sa)->prev = NULL;
        if (*sb)
            (*sb)->prev = head;
        head->next = *sb;
        head->prev = NULL;
        (*sb) = head;
        ft_printf("pb\n"); 
    }
    else if (n == 2)
        push_b(sa, sb);
}

void reverse_rotate(stack_node **stack, int n)
{
    stack_node *last_node;
    stack_node *head;

    head = *stack;
    last_node = find_last_node(*stack);
    *stack = last_node;
    last_node->next = head;
    last_node->prev->next = NULL;
    last_node->prev = NULL;
    head->prev = last_node;
    if (n == 1)
        write(1, "rra\n", 4);
    if (n == 2)
        write(1, "rrb\n", 4);
}

void rrr(stack_node **sa, stack_node **sb, int n)
{
    reverse_rotate (sa, n);
    reverse_rotate (sb, n);
    if (!n)
        write(1, "rrr\n", 4);
}

void reverse_rotate_same_time(stack_node **sa, stack_node **sb, stack_node *cheapest)
{
    while (*sa != cheapest && *sb != cheapest->target_node)
    {
        rrr(sa, sb, 0);
        set_index(*sa);
        set_index(*sb);
    }
}