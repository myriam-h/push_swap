/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:51:13 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 20:51:13 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	transf_b_to_a(t_stack_node **sb, t_stack_node **sa)
{
	if (!*sb)
		return ;
	top_process(sa, (*sb)->target_node, 1);
	push(sa, sb, 2);
}

void	set_target_node_sb(t_stack_node *sa, t_stack_node *sb)
{
	t_stack_node	*second;
	t_stack_node	*max_closest;

	while (sb)
	{
		max_closest = NULL;
		second = sa;
		while (second)
		{
			if (sb->data < second->data && (!max_closest
					|| max_closest->data > second->data))
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

void	oper_on_b(t_stack_node *sa, t_stack_node *sb)
{
	set_index(sa);
	set_index(sb);
	set_target_node_sb(sa, sb);
}
