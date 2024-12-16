#include "../push_swap.h"

void special_case(stack_node **sa, stack_node **sb, stack_node *cheapest)
{
    int size_a;

    size_a = stack_size(*sa);
    if (size_a - (*sa)->index == (*sa)->target_node->index)
    {
        if ((*sa)->next || (*sa)->target_node->next)
        {
            reverse_rotate_same_time(sa, sb, cheapest);
            set_index(*sa);
            set_index(*sb);
        }
    }
}

stack_node *is_cheapest_node(stack_node *sa)
{
    stack_node *cheapest;

    cheapest = sa;
    while (sa)
    {
        if (sa->cheapest_cost)
            cheapest = sa;
        sa = sa->next;
    }
    return (cheapest);
}

void transf_a_to_b(stack_node **sa, stack_node **sb)
{
    stack_node *cheapest;
    
    cheapest = is_cheapest_node(*sa);
    if ((*sa)->above_median && (*sa)->target_node->above_median)
        rotate_same_time(sa, sb, cheapest);
    else if (!(*sa)->above_median && !(*sa)->target_node->above_median)
        reverse_rotate_same_time(sa, sb, cheapest);
    else if (!(*sa)->above_median && (*sa)->target_node->above_median)
        special_case(sa, sb, cheapest);
    top_process(sa, cheapest, 1);
    top_process(sb, cheapest->target_node, 2);
    push(sa, sb, 1);
}