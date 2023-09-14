/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:34:38 by anporced          #+#    #+#             */
/*   Updated: 2023/09/03 15:48:07 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

extern t_headerstruct	g_header;

int	verif_param(int nArg, char **arg)
{
	int	n_char;

	if (nArg != 2)
		return (2);
	n_char = 0;
	while (arg[1][n_char] != 0)
	{
		n_char++;
	}
	if (n_char != 31)
	{
		return (2);
	}
	n_char = 1;
	while (n_char < 31)
	{
		if (arg[1][n_char] != ' ')
			return (2);
		n_char += 2;
	}
	lire_param(arg[1]);
	return (0);
}

int	verif_ligne(int l1, int l2)
{
	unsigned char	i;

	i = 0;
	while (i < 4)
	{
		if (g_header.tab[l1][i] == g_header.tab[l2][i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	affiche_solution(void)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			temp = g_header.tab[i][j] + '0';
			write(1, &temp, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	resultat(int trouve)
{
	if (trouve == 1)
	{
		affiche_solution();
	}
	else
		write(2, "Error!\n", 7);
}
