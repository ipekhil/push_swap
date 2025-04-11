#include "push_swap.h"

char	*remove_quotes_from_string(char *str)
{
	char	*clean_str;
	int		i;
	int		len;


	clean_str = malloc((int)ft_strlen(str) + 1);
	if (!clean_str)
		return (NULL);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != '\'' && str[i] != '\"')
			clean_str[len++] = str[i];
		i++;
	}
	clean_str[len] = '\0';
	return (clean_str);
}

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

int is_in_stack(t_stack *stack, int number)
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
	char	*cleaned;
	char	**split;
	int		i;
	int		j;
	int		num;

	i = 1;
	while (argv[i])
	{
		cleaned = remove_quotes_from_string(argv[i]);
		split = ft_split(cleaned, ' ');
		free(cleaned);
		j = 0;
		while (split[j])
		{
			num = ft_atoi(split[j]);
			if (!is_number(split[j]) || is_in_stack(*stack, num) || !add_to_stack(stack, num))
				return (free_split(split), 0);
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}
