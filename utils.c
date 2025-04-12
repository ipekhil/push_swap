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

int	is_same(char *input, char *check)
{
	int	i = 0;
	int	j = 0;

	if (input[i] == '-' || input[i] == '+')
	{
		i++;
		j++;
	}

	while (input[i] == '0')
		i++;
	while (check[j] == '0')
        j++;
	while (input[i] && check[j])
	{
		if (input[i++] != check[j++])
			return (0);
	}
	if (input[i] == '\0' && check[j] == '\0')
		return (1);
	return (0);
}

static int	check_number(char *str, int num)
{
	char	*check;
	int		result;

	check = ft_itoa(num);
	if (!check)
		return (0);
	result = is_same(str, check);
	free(check);
	return (result);
}

int	is_in_limit(char **argv)
{
	int		i;
	char	**split;
	int		j;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			if (!check_number(split[j], ft_atoi(split[j])))
			{
				free_split(split);
				return (0);
			}
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}
