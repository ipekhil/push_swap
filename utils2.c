/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiipek <hiipek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:00:14 by hiipek            #+#    #+#             */
/*   Updated: 2025/04/13 14:00:51 by hiipek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int	is_same(char *input, char *check)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
