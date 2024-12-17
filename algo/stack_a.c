/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:51:19 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 20:51:19 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_cheapest_cost(t_stack_node *sa)
{
	t_stack_node	*lowest_cost;
	t_stack_node	*head;

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
		if (!lowest_cost->cheapest_cost
			|| head->push_cost < lowest_cost->push_cost)
			lowest_cost = head;
		head = head->next;
	}
	if (lowest_cost)
		lowest_cost->cheapest_cost = true;
}

void	set_target_node_sa(t_stack_node *sa, t_stack_node *sb)
{
	t_stack_node	*second;
	t_stack_node	*min_closest;

	while (sa)
	{
		min_closest = NULL;
		second = sb;
		while (second)
		{
			if (sa->data > second->data && (!min_closest
					|| min_closest->data < second->data))
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

void	set_index(t_stack_node *stack)
{
	int	ind;
	int	median;

	median = stack_size(stack) / 2;
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

void	oper_on_a(t_stack_node *sa, t_stack_node *sb)
{
	set_index(sa);
	set_index(sb);
	set_target_node_sa(sa, sb);
	set_push_cost(sa, stack_size(sa), stack_size(sb));
	set_cheapest_cost(sa);
}
