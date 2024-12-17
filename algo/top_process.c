/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabchi <mhabchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:51:08 by mhabchi           #+#    #+#             */
/*   Updated: 2024/12/17 20:51:08 by mhabchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	top_process(t_stack_node **stack, t_stack_node *node, int n)
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
