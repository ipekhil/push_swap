/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:02:19 by hiipek            #+#    #+#             */
/*   Updated: 2025/04/11 23:54:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack	**from, t_stack	**to)
{
	t_stack	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = tmp->next;
	if (*from)
		(*from)->prev = NULL;
	if (*to)
		(*to)->prev = tmp;
	tmp->next = *to;
	*to = tmp;
}

void	pa(t_stack	**stack_a, t_stack	**stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 4);
}

void	pb(t_stack	**stack_a, t_stack	**stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 4);
}
