#include "../push_swap.h"

void sort(stack_node **sa, stack_node **sb, int numb_nodes)
{
    push(sa, sb, 1);
    numb_nodes--;
    if (numb_nodes-- > 3 && !stack_in_ascend(*sa))
        push(sa, sb, 1);
    while (numb_nodes-- > 3 && !stack_in_ascend(*sa))
    {
        oper_on_a(*sa, *sb);
        transf_a_to_b(sa, sb);
    }
    sort_3(sa);
    while (*sb)
    {
        oper_on_b(*sa, *sb);
        transf_b_to_a(sb, sa);
    }
    set_index(*sa);
    stack_node *min = find_minimum(*sa);
    if (min->above_median)
    {
        while (*sa != min)
            rotate(sa, 1);
    }
    else
        while (*sa != min)
            reverse_rotate(sa, 1);
}

void sort_3(stack_node **sa)
{
    stack_node *biggest;

    biggest = find_maximum(*sa);
    if (biggest == *sa)
        rotate(sa, 1);
    else if (biggest == (*sa)->next)
        reverse_rotate(sa, 1);
    if (!stack_in_ascend(*sa))
        swap(sa, 1);
}

void push_swap(stack_node **sa, stack_node **sb)
{
    if (!stack_in_ascend(*sa))
    {
        if (stack_size(*sa) == 2)
            swap(sa, 1);
        else if (stack_size(*sa) == 3)
            sort_3(sa);
        else
            sort(sa, sb, stack_size(*sa));
    }
}