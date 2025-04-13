/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiipek <hiipek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 23:15:11 by hiipek            #+#    #+#             */
/*   Updated: 2025/04/13 13:45:52 by hiipek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_stack	*stack)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void	assign_index(t_stack	*stack)
{
	int	i;
	int	median;

	i = 0;
	median = list_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (stack->index <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	sort_three(t_stack	**stack)
{
	t_stack	*biggest_node;

	biggest_node = find_highest(*stack);
	if (biggest_node == *stack)
		ra(stack);
	else if ((*stack)->next == biggest_node)
		rra(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack);
}

void	bring_min_top(t_stack	**stack_a)
{
	t_stack	*min;

	min = find_smallest(*stack_a);
	take_to_top(stack_a, min, 'a');
}

void	final_rotate(t_stack **stack_a)
{
	assign_index(*stack_a);
	bring_min_top(stack_a);
}
