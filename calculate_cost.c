/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiipek <hiipek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:12:50 by hiipek            #+#    #+#             */
/*   Updated: 2025/04/13 13:53:40 by hiipek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_stack	*stack_a, t_stack	*stack_b)
{
	t_stack	*current_a;
	int		cost_a;
	int		cost_b;
	int		total_cost;

	current_a = stack_a;
	while (current_a && current_a->target_node)
	{
		if (current_a->above_median)
			cost_a = current_a->index;
		else
			cost_a = list_size(stack_a) - current_a->index;
		if (current_a->target_node->above_median)
			cost_b = current_a->target_node->index;
		else
			cost_b = list_size(stack_b) - current_a->target_node->index;
		if (cost_b > cost_a)
			total_cost = cost_b;
		else
			total_cost = cost_a;
		current_a->cost = total_cost;
		current_a = current_a->next;
	}	
}

t_stack	*get_cheapest(t_stack	*stack_a)
{
	t_stack	*current_a;
	t_stack	*cheapest_node;

	cheapest_node = stack_a;
	current_a = stack_a->next;
	while (current_a)
	{
		if (current_a->cost < cheapest_node->cost)
			cheapest_node = current_a;
		current_a = current_a->next;
	}
	return (cheapest_node);
}

void	take_to_top(t_stack	**stack, t_stack	*node, char stack_name)
{
	while (*stack != node)
	{
		if (node->above_median)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}	
}

void	do_cheapest_move_to_b(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest && cheapest->target_node && \
		cheapest->above_median && cheapest->target_node->above_median)
	{
		while ((*stack_a != cheapest) && (*stack_b != cheapest->target_node))
			rr(stack_a, stack_b);
	}
	else if (!(cheapest->above_median) && \
			!(cheapest->target_node->above_median))
	{
		while ((*stack_a != cheapest) && (*stack_b != cheapest->target_node))
			rrr(stack_a, stack_b);
	}
	take_to_top(stack_a, cheapest, 'a');
	take_to_top(stack_b, cheapest->target_node, 'b');
	pb(stack_a, stack_b);
}
