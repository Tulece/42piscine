/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:33:30 by anporced          #+#    #+#             */
/*   Updated: 2023/09/03 15:47:06 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	test_tab(void);

t_headerstruct	g_header;

const char		g_ref[24][4] = {
{1, 2, 3, 4},
{1, 2, 4, 3},
{1, 3, 2, 4},
{1, 3, 4, 2},
{1, 4, 2, 3},
{1, 4, 3, 2},
{2, 1, 3, 4},
{2, 1, 4, 3},
{2, 3, 1, 4},
{2, 3, 4, 1},
{2, 4, 1, 3},
{2, 4, 3, 1},
{3, 1, 2, 4},
{3, 1, 4, 2},
{3, 2, 1, 4},
{3, 2, 4, 1},
{3, 4, 1, 2},
{3, 4, 2, 1},
{4, 1, 2, 3},
{4, 1, 3, 2},
{4, 2, 1, 3},
{4, 2, 3, 1},
{4, 3, 1, 2},
{4, 3, 2, 1}};

void	remplir(char l[4], int val)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		l[i] = g_ref[val][i];
		i++;
	}
}

void	lire_param(char *arg)
{
	g_header.h[0] = arg[0] - 48;
	g_header.h[1] = arg[2] - 48;
	g_header.h[2] = arg[4] - 48;
	g_header.h[3] = arg[6] - 48;
	g_header.b[0] = arg[8] - 48;
	g_header.b[1] = arg[10] - 48;
	g_header.b[2] = arg[12] - 48;
	g_header.b[3] = arg[14] - 48;
	g_header.g[0] = arg[16] - 48;
	g_header.g[1] = arg[18] - 48;
	g_header.g[2] = arg[20] - 48;
	g_header.g[3] = arg[22] - 48;
	g_header.d[0] = arg[24] - 48;
	g_header.d[1] = arg[26] - 48;
	g_header.d[2] = arg[28] - 48;
	g_header.d[3] = arg[30] - 48;
}

int	remplir_ligne_4(void)
{
	int	l;
	int	trouve;

	trouve = 0;
	l = 0;
	while (l < 24 && trouve == 0)
	{
		remplir(g_header.tab[3], l);
		if (verif_ligne(0, 3)
			&& verif_ligne(1, 3) && verif_ligne(2, 3)
			&& trouve == 0)
		{
			trouve = test_tab();
		}
		l++;
	}
	return (trouve);
}

int	remplir_ligne_3(void)
{
	int	trouve;
	int	k;

	trouve = 0;
	k = 0;
	while (k < 24 && trouve == 0)
	{
		remplir(g_header.tab[2], k);
		if (verif_ligne(0, 2)
			&& verif_ligne(1, 2) && !trouve)
		{
			trouve = remplir_ligne_4();
		}
		k++;
	}
	return (trouve);
}

int	main(int nArg, char *arg[])
{
	int	trouve;
	int	i;
	int	j;

	i = 0;
	trouve = verif_param(nArg, arg);
	while (i < 24 && trouve == 0)
	{
		remplir(g_header.tab[0], i);
		j = 0;
		while (j < 24 && trouve == 0)
		{
			remplir(g_header.tab[1], j);
			if (verif_ligne(0, 1))
				trouve = remplir_ligne_3();
			j++;
		}
		i++;
	}
	resultat(trouve);
}
