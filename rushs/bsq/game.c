/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:53:07 by anporced          #+#    #+#             */
/*   Updated: 2023/09/12 18:53:10 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carre.h"

extern t_jeu	g_jeu;

void	prepare_jeu_1(void)
{
	int	j;

	g_jeu.lv[0][0] = 1 - g_jeu.tab[0][0];
	g_jeu.lh[0][0] = 1 - g_jeu.tab[0][0];
	j = 1;
	while (j < g_jeu.nb_col)
	{
		g_jeu.tmin[j] = 0;
		g_jeu.lv[0][j] = 1 - g_jeu.tab[0][j];
		if (g_jeu.tab[0][j] == 1)
			g_jeu.lh[0][j] = 0;
		else
			g_jeu.lh[0][j] = g_jeu.lh[0][j - 1] + 1;
		j++;
	}
	j = 1;
	while (j < g_jeu.nb_lig)
	{
		g_jeu.lh[j][0] = 1 - g_jeu.tab[j][0];
		if (g_jeu.tab[0][j] == 1)
			g_jeu.lv[j][0] = 0;
		else
			g_jeu.lv[j][0] = g_jeu.lv[j - 1][0] + 1;
		j++;
	}
}

void	prepare_jeu(void)
{
	int	i;
	int	j;

	prepare_jeu_1();
	i = 1;
	while (i < g_jeu.nb_lig)
	{
		j = 1;
		while (j < g_jeu.nb_col)
		{
			if (g_jeu.tab[i][j] == 1)
			{
				g_jeu.lv[i][j] = 0;
				g_jeu.lh[i][j] = 0;
			}
			else
			{
				g_jeu.lv[i][j] = g_jeu.lv[i - 1][j] + 1;
				g_jeu.lh[i][j] = g_jeu.lh[i][j - 1] + 1;
			}
			j++;
		}
		i++;
	}
	g_jeu.max = 0;
}

void	fin_jeu(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_jeu.max)
	{
		j = 0;
		while (j < g_jeu.max)
		{
			g_jeu.tab[g_jeu.y - i][g_jeu.x - j] = 2;
			j++;
		}
		i++;
	}
}

void	resolve_jeu(void)
{
	int	i;
	int	j;
	int	m;

	i = g_jeu.nb_lig - 1;
	while (i >= g_jeu.max - 1)
	{
		j = g_jeu.nb_col - 1;
		while (j >= g_jeu.max - 1)
		{
			m = taille_max(j, i);
			if (g_jeu.max <= m)
			{
				g_jeu.max = m;
				g_jeu.x = j;
				g_jeu.y = i;
			}
			j--;
		}
		i--;
	}
	fin_jeu();
}

void	jouer(char *name)
{
	if (lire_jeu(name))
	{
		prepare_jeu();
		resolve_jeu();
		affiche();
		libere_jeu();
	}
	else
		write(2, "map error\n", 11);
}
