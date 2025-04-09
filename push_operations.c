/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilalipek <hilalipek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:34:58 by hilalipek         #+#    #+#             */
/*   Updated: 2025/04/09 18:35:19 by hilalipek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
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
t_stack *new_node(int nbr)
{
	t_stack *node = malloc(sizeof(t_stack));
	node->nbr = nbr;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

// Stack'e başa ekle
void add_node(t_stack **stack, int nbr)
{
	t_stack *node = new_node(nbr);
	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}

// Stack'i yazdır
void print_stack(t_stack *stack, char name)
{
	printf("Stack %c: ", name);
	while (stack)
	{
		printf("%d ", stack->nbr);
		stack = stack->next;
	}
	printf("\n");
}
int main(void)
{
	t_stack *a = NULL;
	t_stack *b = NULL;

	add_node(&a, 1);
	add_node(&a, 2);
	add_node(&a, 3);

	printf("İlk Hali:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');

	pb(&a, &b); // 3 B'ye gidecek
	print_stack(a, 'A');
	print_stack(b, 'B');

	pb(&a, &b); // 2 B'ye gidecek
	print_stack(a, 'A');
	print_stack(b, 'B');	
	
	pb(&a, &b); // 1 B'ye gidecek
	print_stack(a, 'A');
	print_stack(b, 'B');	

	pa(&a, &b); // 2 geri A'ya
	print_stack(a, 'A');
	print_stack(b, 'B');

	return 0;
}