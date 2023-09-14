/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestMem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:53:29 by anporced          #+#    #+#             */
/*   Updated: 2023/09/12 18:53:32 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carre.h"

extern t_jeu	g_jeu;

int	alloc_tableau_principaux(void)
{
	g_jeu.tab = malloc(g_jeu.nb_lig * sizeof(char *));
	if (g_jeu.tab == NULL)
		return (0);
	g_jeu.lh = malloc(g_jeu.nb_lig * sizeof(unsigned short int *));
	if (g_jeu.lh == NULL)
		return (0);
	g_jeu.lv = malloc(g_jeu.nb_lig * sizeof(unsigned short int *));
	if (g_jeu.lh == NULL)
		return (0);
	g_jeu.tmin = malloc(g_jeu.nb_col * sizeof(unsigned short int));
	if (g_jeu.tmin == NULL)
		return (0);
	return (1);
}

int	alloc_jeu(void)
{
	int	i;

	if (alloc_tableau_principaux() == 0)
	{
		return (0);
	}
	i = -1;
	while (++i < g_jeu.nb_lig)
	{
		g_jeu.tab[i] = malloc(g_jeu.nb_col * sizeof(char));
		if (g_jeu.tab[i] == NULL)
			return (0);
		g_jeu.lh[i] = malloc(g_jeu.nb_col * sizeof(unsigned short int));
		if (g_jeu.lh[i] == NULL)
			return (0);
		g_jeu.lv[i] = malloc(g_jeu.nb_col * sizeof(unsigned short int));
		if (g_jeu.lv[i] == NULL)
			return (0);
	}
	return (1);
}

void	libere_jeu(void)
{
	int	i;

	if (g_jeu.tab != NULL)
	{
		i = 0;
		while (i < g_jeu.nb_lig && g_jeu.tab[i] != NULL)
			free(g_jeu.tab[i++]);
		free(g_jeu.tab);
	}
	if (g_jeu.lh != NULL)
	{
		i = 0;
		while (i < g_jeu.nb_lig && g_jeu.lh[i] != NULL)
			free(g_jeu.lh[i++]);
		free(g_jeu.lh);
	}
	if (g_jeu.lv != NULL)
	{
		i = 0;
		while (i < g_jeu.nb_lig && g_jeu.lv[i] != NULL)
			free(g_jeu.lv[i++]);
		free(g_jeu.lv);
	}
	free(g_jeu.tmin);
}

int	taille_max(int c, int l)
{
	int	m;

	m = g_jeu.tmin[c];
	while (l - m >= 0 && c - m >= 0 && g_jeu.lv[l][c - m] > m
			&& g_jeu.lh[l - m][c] > m)
	{
		m++;
	}
	if (m == 0)
		g_jeu.tmin[c] = 0;
	else
		g_jeu.tmin[c] = m - 1;
	return (m);
}
