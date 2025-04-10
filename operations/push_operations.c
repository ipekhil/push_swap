/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiipek <hiipek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:02:19 by hiipek            #+#    #+#             */
/*   Updated: 2025/04/09 23:17:29 by hiipek           ###   ########.fr       */
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
	printf("pa\n");
}

void	pb(t_stack	**stack_a, t_stack	**stack_b)
{
	push(stack_a, stack_b);
	printf("pb\n");
}
