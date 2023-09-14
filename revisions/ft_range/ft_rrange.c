/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:32:16 by anporced          #+#    #+#             */
/*   Updated: 2023/09/14 22:38:05 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_rrange(int start, int end)
{
	int	size;
	int	*range;
	int	i;

	i = 0;
	if (start > end)
		return (ft_rrange(end, start));
	size = end - start + 1;
	range = malloc(sizeof(int) * size);
	if (range)
	{
		while (i < size)
		{
			range[i] = start;
			start++;
			i++;
		}
	}
	return (range);
}
