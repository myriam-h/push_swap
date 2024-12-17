/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:51:37 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 20:51:37 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack_node **sa, t_stack_node **sb, int numb_nodes)
{
	t_stack_node	*min;

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
	min = find_minimum(*sa);
	min_pos(sa, min);
}

void	sort_3(t_stack_node **sa)
{
	t_stack_node	*biggest;

	biggest = find_maximum(*sa);
	if (biggest == *sa)
		rotate(sa, 1);
	else if (biggest == (*sa)->next)
		reverse_rotate(sa, 1);
	if (!stack_in_ascend(*sa))
		swap(sa, 1);
}

void	push_swap(t_stack_node **sa, t_stack_node **sb)
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

void	min_pos(t_stack_node **sa, t_stack_node *min)
{
	if (min->above_median)
	{
		while (*sa != min)
			rotate(sa, 1);
	}
	else
	{
		while (*sa != min)
			reverse_rotate(sa, 1);
	}
}
