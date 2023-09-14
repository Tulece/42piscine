/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 17:26:10 by tmalbeck          #+#    #+#             */
/*   Updated: 2023/09/10 20:38:43 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_cond1(int size, char **dict, int i, int j)
{
	if (i != size - 1 && ft_strlen(dict[j]) == (1 + (size - 1 - i) * 3))
	{
		if (dict[j + 1][0] < '0' || dict[j + 1][0] > '9')
		{
			return (1);
		}
	}
	return (0);
}

int	ft_cond2(char *number)
{
	if (number[0] != '0' || number[1] != '0' || number[2] != '0')
		return (1);
	return (0);
}

int	ft_check_dict(char **dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i])
	{
		j = 0;
		while (dict[i][j] != '\0')
		{
			if (!(dict[i][j] >= '0' && dict[i][j] <= '9')
				&& !(dict[i][j] >= 'a' && dict[i][j] <= 'z')
				&& !(dict[i][j] >= 'A' && dict[i][j] <= 'Z'))
			{
				ft_error("Error: Invalid dictionary.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
