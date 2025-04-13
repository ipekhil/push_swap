/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiipek <hiipek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:58:38 by hiipek            #+#    #+#             */
/*   Updated: 2025/04/13 13:58:39 by hiipek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack	*stack)
{
	while (stack && stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

int	is_duplicated(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*cmp;

	curr = stack;
	while (curr)
	{
		cmp = curr->next;
		while (cmp)
		{
			if (curr->nbr == cmp->nbr)
				return (1);
			cmp = cmp->next;
		}
		curr = curr->next;
	}
	return (0);
}
