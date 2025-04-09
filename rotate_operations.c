/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilalipek <hilalipek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:50:36 by hilalipek         #+#    #+#             */
/*   Updated: 2025/04/09 15:36:56 by hilalipek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack	**stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !*stack->next)
		return ;

	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	*stack->prev = NULL;

	last->next = first;
	first->prev = last;
	first->next = NULL;
	
}

void	ra(t_stack	**stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack	**stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack	**stack_a, t_stack	**stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
void	reverse_rotate(t_stack	**stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !*stack->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*stack = last;
}

void	rra(t_stack	**stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack	**stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack	**stack_a, t_stack	**stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}