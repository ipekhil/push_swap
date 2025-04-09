/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilalipek <hilalipek@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:31:15 by hiipek            #+#    #+#             */
/*   Updated: 2025/04/06 15:44:04 by hilalipek        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*a;

	a = (char *)b;
	while (len != 0)
	{
		len--;
		a[len] = c;
	}
	return ((void *)b);
}
