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
		i++, j++; // işaret varsa atla

	while (input[i] == '0') // baştaki sıfırları atla
		i++;

	while (input[i] && check[j])
	{
		if (input[i++] != check[j++])
			return (0);
	}
	return (input[i] == '\0' && check[j] == '\0');
}
int	is_in_limit(char **argv)
{
	int		i = 1;
	int		tmp;
	char	**split;
	char	*check;
	int		j;
	char	*cleaned;

	while (argv[i])
	{
		cleaned = remove_quotes_from_string(argv[i]);
		split = ft_split(cleaned, ' ');
		free(cleaned);
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			tmp = ft_atoi(split[j]);
			check = ft_itoa(tmp);
			if (!is_same(split[j], check))
			{
				free(check);
				free_split(split);
				return (0);
			}
			free(check);
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}
