#include "../push_swap.h"

void swap(stack_node **stack, int n)
{
    *stack = (*stack)->next;
    (*stack)->prev->prev = *stack;
    (*stack)->prev->next = (*stack)->next;
    if ((*stack)->next)
        (*stack)->next->prev = (*stack)->prev;
    (*stack)->next = (*stack)->prev;
    (*stack)->prev = NULL;
    if (n == 1)
        write(1, "sa\n", 3);
    else if (n == 2)
        write(1, "sb\n", 3);
}

void rotate(stack_node **stack, int n)
{
    stack_node *last_node;

    last_node = find_last_node(*stack);
    *stack = (*stack)->next;
    (*stack)->prev->prev = last_node;
    last_node->next = (*stack)->prev;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
    if (n == 1)
        write(1, "ra\n", 3);
    else if (n == 2)
        write(1, "rb\n", 3);
}

void rr(stack_node **sa, stack_node **sb, int n)
{
    rotate (sa, n);
    rotate (sb, n);
    if (!n)
        write(1, "rr\n", 3);
}

void rotate_same_time(stack_node **sa, stack_node **sb, stack_node *cheapest)
{
    while (*sa != cheapest && *sb != cheapest->target_node)
    {
        rr(sa, sb, 0);
        set_index(*sa);
        set_index(*sb);
    }
}