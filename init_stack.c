/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiipek <hiipek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:53:57 by hiipek            #+#    #+#             */
/*   Updated: 2025/04/13 13:53:58 by hiipek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char	*str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	add_to_stack(t_stack	**stack, int number)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->nbr = number;
	new->index = 0;
	new->cost = 0;
	new->above_median = false;
	new->target_node = NULL;
	new->prev = NULL;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		return (1);
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
	return (1);
}

int	is_in_stack(t_stack *stack, int number)
{
	while (stack)
	{
		if (stack->nbr == number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	fill_stack(t_stack	**stack, char **argv)
{
	char	**split;
	int		i;
	int		j;
	int		num;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			num = ft_atoi(split[j]);
			if (!is_number(split[j]) || \
				is_in_stack(*stack, num) || !add_to_stack(stack, num))
				return (free_split(split), 0);
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}

int	init_stacks(t_stack **stack_a, char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!argv[i][0] || is_only_spaces(argv[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	if (!fill_stack(stack_a, argv))
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
		return (0);
	}
	if (is_duplicated(*stack_a) || !is_in_limit(argv))
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
		return (0);
	}
	return (1);
}
