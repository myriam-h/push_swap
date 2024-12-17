/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:58:24 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 20:58:24 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clean_stack(t_stack_node **sa)
{
	t_stack_node	*current;
	t_stack_node	*next;

	current = *sa;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*sa = NULL;
}

t_stack_node	*get_last_node(t_stack_node *sa)
{
	t_stack_node	*last_node;

	last_node = sa;
	while (last_node && last_node->next)
		last_node = last_node->next;
	return (last_node);
}

int	add_node(t_stack_node **sa, int num)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return (1);
	new_node->data = num;
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->cheapest_cost = false;
	new_node->above_median = false;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*sa == NULL)
	{
		*sa = new_node;
	}
	else
	{
		last_node = get_last_node(*sa);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	return (0);
}

void	fill_stack(t_stack_node **sa, char **argv)
{
	int	i;
	int	value;

	if (sa == NULL || ft_check(argv))
	{
		clean_array(argv);
		prog_exit(false, sa);
	}
	i = 0;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		if (add_node(sa, value))
		{
			clean_array(argv);
			prog_exit(true, sa);
		}
		i++;
	}
}
