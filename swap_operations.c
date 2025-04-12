/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:02:02 by hiipek            #+#    #+#             */
/*   Updated: 2025/04/11 23:55:13 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack) || !(*stack) -> next)
		return ;
	first = *stack;
	second = (*stack)-> next;
	first -> next = second -> next;
	if (second -> next)
		second -> next ->prev = first;
	second -> prev = NULL;
	second -> next = first;
	first -> prev = second;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1,"sa\n", 4);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1,"sb\n", 4);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1,"ss\n", 4);
}
