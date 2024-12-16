#include "../push_swap.h"

void sa_below_median_cost(stack_node *sa, int size_a, int size_b)
{
    sa->push_cost = size_a - sa->index;
    if (sa->target_node->above_median)
    {
        if (size_a - sa->index == sa->target_node->index)
        {
            if (sa->next || sa->target_node->next)
                sa->push_cost += sa->target_node->index;
        }
        else
            sa->push_cost += sa->target_node->index;
    }
    else
    {
        if (size_a - sa->index != size_b - sa->target_node->index)
        {
            if (size_a - sa->index < size_b - sa->target_node->index)
                sa->push_cost = size_b - sa->target_node->index;
        }
    }
}

void sa_above_median_cost(stack_node *sa, int size_b)
{
    sa->push_cost = sa->index;
    if (sa->target_node->above_median)
    {
        if (sa->index < sa->target_node->index)
            sa->push_cost = sa->target_node->index;
    }
    else
        if (!(sa->index == sa->target_node->index))
            sa->push_cost += (size_b - sa->target_node->index);
}

void set_push_cost(stack_node *sa, int size_a, int size_b)
{
  while (sa)
    {
        if (sa->above_median)
            sa_above_median_cost(sa, size_b);
        
        else
            sa_below_median_cost(sa, size_a, size_b);
        sa = sa->next;
    }
}