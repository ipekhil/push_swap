/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiipek <hiipek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:02:19 by hiipek            #+#    #+#             */
/*   Updated: 2025/04/13 14:01:05 by hiipek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack	**stack_a, t_stack	**stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack	**stack_a, t_stack	**stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	rra(t_stack	**stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack	**stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack	**stack_a, t_stack	**stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
