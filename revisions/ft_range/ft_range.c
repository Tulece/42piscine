/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:26:34 by anporced          #+#    #+#             */
/*   Updated: 2023/09/14 22:32:06 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int start, int end)
{
	int	size;
	int	*range;
	int	i;
	int	value;

	if (start >= end)
		return(NULL);
	size = end - start;
	range = malloc(sizeof(int) * size);
	if (range == NULL)
		return (NULL);
	i = 0;
	value = start;
	while (i < size)
	{
		range[i] = value;
		value++;
		i++;
	}
	return (range);
}
