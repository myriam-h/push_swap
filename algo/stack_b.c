#include "../push_swap.h"

void transf_b_to_a(stack_node **sb, stack_node **sa)
{
    top_process(sa, (*sb)->target_node, 1);
    push(sa, sb, 2);

}

void set_target_node_sb(stack_node *sa, stack_node *sb)
{
    stack_node *second;
    stack_node *max_closest;

    while (sb)
    {
        max_closest = NULL;
        second = sa;
        while (second)
        {
            if (sb->data < second->data && (!max_closest || max_closest->data > second->data))
                max_closest = second;
            second = second->next;
        }
        if (max_closest)
            sb->target_node = max_closest;
        else
            sb->target_node = find_minimum(sa);
        sb = sb->next;
    }
}

void oper_on_b(stack_node *sa, stack_node *sb)
{
    set_index(sa);
    set_index(sb);
    set_target_node_sb(sa, sb);
}