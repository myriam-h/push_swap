/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:51:35 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 20:51:35 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_stack_node **sa, t_stack_node **sb)
{
	t_stack_node	*head;

	if (!*sb)
		return ;
	head = *sb;
	if ((*sb)->next)
	{
		*sb = (*sb)->next;
		(*sb)->prev = NULL;
	}
	else
		*sb = NULL;
	head->next = *sa;
	head->prev = NULL;
	if (*sa)
		(*sa)->prev = head;
	*sa = head;
	ft_printf("pa\n");
}

void	push(t_stack_node **sa, t_stack_node **sb, int n)
{
	t_stack_node	*head;

	if (n == 1)
	{
		if (!*sa)
			return ;
		head = *sa;
		*sa = (*sa)->next;
		if (*sa)
			(*sa)->prev = NULL;
		head->next = *sb;
		head->prev = NULL;
		if (*sb)
			(*sb)->prev = head;
		*sb = head;
		ft_printf("pb\n");
	}
	else if (n == 2)
		push_b(sa, sb);
}

void	reverse_rotate(t_stack_node **stack, int n)
{
	t_stack_node	*last_node;
	t_stack_node	*head;

	if (!*stack || !(*stack)->next)
		return ;
	head = *stack;
	last_node = find_last_node(*stack);
	*stack = last_node;
	last_node->next = head;
	head->prev = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	if (n == 1)
		write(1, "rra\n", 4);
	if (n == 2)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **sa, t_stack_node **sb, int n)
{
	if (!sa || !sb)
		return ;
	reverse_rotate(sa, n);
	reverse_rotate(sb, n);
	if (!n)
		write(1, "rrr\n", 4);
}

void	reverse_rotate_same_time(t_stack_node **sa, t_stack_node **sb,
			t_stack_node *cheapest)
{
	while (*sa != cheapest && *sb != cheapest->target_node)
	{
		rrr(sa, sb, 0);
		set_index(*sa);
		set_index(*sb);
	}
}
