/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 09:12:56 by tmalbeck          #+#    #+#             */
/*   Updated: 2023/09/10 22:42:20 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* Display hundreds */
void	ft_hundreds(char *input, char **dict)
{
	int	i;

	i = 0;
	if (input[0] < '1' || input[0] > '9')
		return ;
	while (dict[i])
	{
		if (dict[i][0] == input[0] && !dict[i][1] && input[0] != '0')
		{
			ft_putstr(dict[i + 1]);
			ft_putstr(" ");
		}
		if (dict[i][0] == '1' && dict[i][1] == '0')
			if (dict[i][2] == '0' && !dict[i][3])
				ft_putstr(dict[i + 1]);
		i++;
	}
	if (input[1] != '0' || input[2] != '0')
	{
		if (ft_get_dict_content("numbers.dict"))
			ft_putstr(" and ");
	}
}

/* Display tens */
void	ft_tens(char *input, char **dict)
{
	int		i;
	char	n[3];

	n[0] = input[1];
	n[2] = 0;
	if (input[1] >= '2')
		n[1] = '0';
	else if (input[1] == '1')
		n[1] = input[2];
	else
		return ;
	i = 0;
	while (dict[i])
	{
		if (dict[i][0] == n[0] && dict[i][1] == n[1] && !dict[i][2])
			ft_putstr(dict[i + 1]);
		i++;
	}
}

/* Display units */
void	ft_units(char *input, char **dict)
{
	int	i;

	i = 0;
	if (input[2] == '0')
		return ;
	while (dict[i])
	{
		if (input[1] == '0' && dict[i][0] == input[2] && !dict[i][1])
			ft_putstr(dict[i + 1]);
		if (input[1] >= '2')
		{
			if (dict[i][0] == input[2] && !dict[i][1] && input[2] != '0')
			{
				ft_putstr("-");
				ft_putstr(dict[i + 1]);
			}
		}
		i++;
	}
}

/* Display numbers with 3 digits */
void	ft_display_100(char *input, char **dict)
{
	ft_hundreds(input, dict);
	ft_tens(input, dict);
	ft_units(input, dict);
}
