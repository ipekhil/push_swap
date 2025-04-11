#include "push_swap.h"

void	push_to_b(t_stack	**stack_a, t_stack	**stack_b)
{
	while (list_size(*stack_a) > 3)
	{
		assign_index(stack_a);
		assign_index(stack_b);
		target_in_b(stack_a, stack_b);
		calculate_cost(stack_a, stack_b);
		do_cheapest_move_to_b(stack_a, stack_b);
	}	
}

void	push_to_a(t_stack	**stack_a, t_stack	**stack_b)
{
	while (*stack_b)
	{
		assign_index(stack_a);
		assign_index(stack_b);
		target_in_a(stack_a, stack_b);
		take_to_top(stack_a, (*stack_b)->target_node, 'a');
		pa(stack_a, stack_b);
	}	
}
void	bring_min_top(t_stack	**stack_a)
{
	t_stack	*min;

	min = find_smallest(*stack_a);
	take_to_top(stack_a, min, 'a');
}

void	final_rotate(t_stack	**stack_a)
{
	assign_index(stack_a);
	bring_min_top(stack_a);
}

void	push_swap(t_stack	**stack_a, t_stack	**stack_b)
{
	if (list_size(*stack_a) == 2)
	{
		if ((*stack_a)->nbr > (*stack_a)->next->nbr)
			sa(stack_a);
		return ;
	}
	if (list_size(*stack_a) == 3)
	{
		sort_three(stack_a);
		return ;
	}
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	push_to_a(stack_a, stack_b);
	final_rotate(stack_a);
}

