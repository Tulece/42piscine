/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:17:04 by anporced          #+#    #+#             */
/*   Updated: 2023/09/03 15:46:19 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_headerstruct
{
	char	tab[4][4];
	char	h[4];
	char	b[4];
	char	g[4];
	char	d[4];
}	t_headerstruct;

int		verif_gauche(int l);
int		verif_droite(int l);
int		verif_haut(int l);
int		verif_bas(int l);
int		test_tab(void);
void	remplir(char l[4], int val);
void	lire_param(char *arg);
void	affiche_solution(void);
void	resultat(int trouve);
int		remplir_ligne_4(void);
int		remplir_ligne_3(void);
int		verif_ligne(int l1, int l2);
int		verif_param(int nArg, char **arg);
