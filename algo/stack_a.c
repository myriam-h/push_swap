#include "../push_swap.h"

void set_cheapest_cost(stack_node *sa)
{
    stack_node *lowest_cost;
    stack_node *head;

    head = sa;
    while (head)
    {
        head->cheapest_cost = false;
        head = head->next;
    }
    head = sa;
    lowest_cost = sa;
    while (head)
    {
        if (lowest_cost->cheapest_cost > head->cheapest_cost)
            lowest_cost = head;
        head = head->next;
    }
    lowest_cost->cheapest_cost = true;
}

void set_target_node_sa(stack_node *sa, stack_node *sb)
{
    stack_node *second;
    stack_node *min_closest;

    while (sa)
    {
        min_closest = NULL;
        second = sb;
        while (second)
        {
            if (sa->data > second->data && (!min_closest || min_closest->data < second->data))
                min_closest = second;
            second = second->next;
        }
        if (min_closest)
            sa->target_node = min_closest;
        else
            sa->target_node = find_maximum(sb);
        sa = sa->next;
    }
}

void set_index(stack_node *stack)
{
    int ind;
    int median;

    median = (stack_size(stack) / 2);
    ind = 0;
    while (stack)
    {
        stack->index = ind;
        if (ind <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        ind++;
        stack = stack->next;
    }
}

void oper_on_a(stack_node *sa, stack_node *sb)
{
    set_index(sa);
    set_index(sb);
    set_target_node_sa(sa, sb);
    set_push_cost(sa, stack_size(sa), stack_size(sb));
    set_cheapest_cost(sa);
}