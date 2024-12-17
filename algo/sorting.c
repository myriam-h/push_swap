/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:51:25 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 20:51:25 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack_node	*find_last_node(t_stack_node *stack)
{
	t_stack_node	*last_node;

	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	last_node = stack;
	return (last_node);
}

t_stack_node	*find_minimum(t_stack_node *stack)
{
	t_stack_node	*minimum;

	if (!stack)
		return (NULL);
	minimum = stack;
	while (stack)
	{
		if (stack->data < minimum->data)
			minimum = stack;
		stack = stack->next;
	}
	return (minimum);
}

t_stack_node	*find_maximum(t_stack_node *stack)
{
	t_stack_node	*maximum;

	if (!stack)
		return (NULL);
	maximum = stack;
	while (stack)
	{
		if (stack->data > maximum->data)
			maximum = stack;
		stack = stack->next;
	}
	return (maximum);
}

int	stack_in_ascend(t_stack_node *sa)
{
	while (sa && sa->next)
	{
		if (sa->data > sa->next->data)
			return (0);
		sa = sa->next;
	}
	return (1);
}

int	stack_size(t_stack_node *sa)
{
	int	count;

	count = 0;
	while (sa)
	{
		count++;
		sa = sa->next;
	}
	return (count);
}
