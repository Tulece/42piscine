/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_sol.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:34:11 by anporced          #+#    #+#             */
/*   Updated: 2023/09/03 10:23:09 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern t_headerstruct	g_header;

int	verif_gauche(int l)
{
	char			t;
	char			n;
	unsigned char	i;

	t = 0;
	n = 0;
	i = 0;
	while (i < 4)
	{
		if (g_header.tab[l][i] > t)
		{
			n++;
			t = g_header.tab[l][i];
		}
		i++;
	}
	if (g_header.g[l] != n)
	{
		return (0);
	}
	return (1);
}

int	verif_droite(int l)
{
	int	t;
	int	n;
	int	i;

	t = 0;
	n = 0;
	i = 3;
	while (i >= 0)
	{
		if (g_header.tab[l][i] > t)
		{
			n++;
			t = g_header.tab[l][i];
		}
		i--;
	}
	if (g_header.d[l] != n)
	{
		return (0);
	}
	return (1);
}

int	verif_haut(int l)
{
	int	t;
	int	n;
	int	i;

	t = 0;
	n = 0;
	i = 0;
	while (i < 4)
	{
		if (g_header.tab[i][l] > t)
		{
			n++;
			t = g_header.tab[i][l];
		}
		i++;
	}
	if (g_header.h[l] != n)
	{
		return (0);
	}
	return (1);
}

int	verif_bas(int l)
{
	int	t;
	int	n;
	int	i;

	t = 0;
	n = 0;
	i = 3;
	while (i >= 0)
	{
		if (g_header.tab[i][l] > t)
		{
			n++;
			t = g_header.tab[i][l];
		}
		i--;
	}
	if (g_header.b[l] != n)
	{
		return (0);
	}
	return (1);
}

int	test_tab(void)
{
	char	l;

	l = 0;
	while (l < 4)
	{
		if (verif_haut(l) == 0)
			return (0);
		if (verif_bas(l) == 0)
			return (0);
		if (verif_gauche(l) == 0)
			return (0);
		if (verif_droite(l) == 0)
			return (0);
		l++;
	}
	return (1);
}
