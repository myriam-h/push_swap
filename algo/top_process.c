#include "../push_swap.h"

void top_process(stack_node **stack, stack_node *node, int n)
{
    while (*stack != node)
    {
        if (n == 1)
        {
            if (node->above_median)
                rotate(stack, 1);
            else
                reverse_rotate(stack, 1);
        }
        else if (n == 2)
        {
            if (node->above_median)
                rotate(stack, 2);
            else
                reverse_rotate(stack, 2);
        }
    }
}