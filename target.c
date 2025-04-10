/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiipek <hiipek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 05:13:56 by hiipek            #+#    #+#             */
/*   Updated: 2025/04/10 05:56:31 by hiipek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_in_b(t_stack	*stack_a, t_stack	*stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_stack	*target;
	int		max_under;

	
	current_a = stack_a;
	current_b = stack_b;
	while (current_a)
	{
		while (current_b)
		{
			if (current_a->nbr > current_b->nbr)
			{
				
			}
			
			current_b = current_b->next;
		}
		current_a = current_a->next;
	}
	
}

