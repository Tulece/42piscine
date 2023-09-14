/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:56:09 by anporced          #+#    #+#             */
/*   Updated: 2023/09/11 14:02:44 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	value;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = malloc(sizeof(int) * size);
	if (!(*range))
		return (-1);
	i = 0;
	value = min;
	while (i < size)
	{
		(*range)[i] = value;
		i++;
		value++;
	}
	return (size);
}
