/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readPrint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:54:10 by anporced          #+#    #+#             */
/*   Updated: 2023/09/12 18:55:20 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carre.h"

extern t_jeu	g_jeu;

int	lire_jeu_2(int fd)
{
	char	c;

	g_jeu.nb_col = 0;
	while (read(fd, &c, 1) == 1 && c != '\n')
	{
		if (c != g_jeu.car[0] && c != g_jeu.car[1])
			return (-1 - fd);
		g_jeu.ligne1[g_jeu.nb_col] = (char)(c == g_jeu.car[1]);
		g_jeu.nb_col++;
	}
	if (c != '\n' || g_jeu.nb_col == 0)
		return (-1 - fd);
	return (fd);
}

int	lire_jeu_1_2(char *name)
{
	int		fd;
	char	c;
	int		n;
	int		v;

	v = -1;
	n = 0;
	if (name != NULL)
		fd = open(name, O_RDONLY);
	g_jeu.nb_lig = 0;
	while (read(fd, &c, 1) == 1 && c != '\n')
		n++;
	fd = open(name, O_RDONLY);
	while (read(fd, &c, 1) == 1 && c >= '0' && c <= '9' && ++v < n - 3)
		g_jeu.nb_lig = g_jeu.nb_lig * 10 + c - 48;
	if (g_jeu.nb_lig == 0)
		return (-1 - fd);
	g_jeu.car[0] = c;
	if (read(fd, g_jeu.car + 1, 2) != 2
		|| g_jeu.car[0] < 32 || g_jeu.car[1] < 32 || g_jeu.car[2] < 32
		|| g_jeu.car[0] == g_jeu.car[1] || g_jeu.car[0] == g_jeu.car[2]
		|| g_jeu.car[1] == g_jeu.car[2] || (read(fd, &c, 1) != 1 && c != '\n'))
		return (-1 - fd);
	return (lire_jeu_2(fd));
}

int	lire_jeu_2_n(int fd)
{
	int		i;
	int		j;
	char	c;
	int		ret;

	free(g_jeu.tab[0]);
	g_jeu.tab[0] = g_jeu.ligne1;
	i = 1;
	ret = 1;
	while (i < g_jeu.nb_lig && ret == 1)
	{
		j = 0;
		while (read(fd, &c, 1) == 1 && c != '\n'
			&& j <= g_jeu.nb_col && ret == 1)
		{
			if (c != g_jeu.car[0] && c != g_jeu.car[1])
				ret = 0;
			g_jeu.tab[i][j++] = (char)(c == g_jeu.car[1]);
		}
		if (j != g_jeu.nb_col)
			ret = 0;
		i++;
	}
	return (ret);
}

/**
 * lecture du jeu avec les allocation memoire si ok
 * @param name : nom du fichier NULL si entree standard
 * @return 1 si ok 0 sinon
 */
int	lire_jeu(char *name)
{
	int	fd;

	g_jeu.ligne1 = malloc(TAILLE_MAX * sizeof(char));
	if (g_jeu.ligne1 == NULL)
		return (0);
	fd = lire_jeu_1_2(name);
	if (fd < 0)
	{
		if (g_jeu.ligne1 != NULL)
			free(g_jeu.ligne1);
		if (fd != -1)
			close(fd - 1);
		return (0);
	}
	if (!alloc_jeu() || !lire_jeu_2_n(fd))
	{
		if (fd != 0)
			close(fd);
		libere_jeu();
		return (0);
	}
	if (fd != 0)
		close(fd);
	return (1);
}

void	affiche(void)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < g_jeu.nb_lig)
	{
		j = 0;
		while (j < g_jeu.nb_col)
		{
			c = g_jeu.car[(int) g_jeu.tab[i][j++]];
			write(1, &c, 1);
		}
		c = '\n';
		write(1, &c, 1);
		i++;
	}
}
