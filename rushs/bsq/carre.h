/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carre.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:52:43 by anporced          #+#    #+#             */
/*   Updated: 2023/09/12 18:52:48 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARRE_H
# define CARRE_H

# include <unistd.h>
# include <malloc.h>
# include <fcntl.h>

# define TAILLE_MAX 100000

typedef struct s_jeu
{
	int					nb_lig;
	int					nb_col;
	char				**tab;
	unsigned short int	**lh;
	unsigned short int	**lv;
	unsigned short int	*tmin;
	int					max;
	int					x;
	int					y;
	char				car[3];
	char				*ligne1;
}	t_jeu;

void	prepare_jeu_1(void);
void	prepare_jeu(void);
void	fin_jeu(void);
void	resolve_jeu(void);
void	jouer(char *name);
int		alloc_tableau_principaux(void);
int		alloc_jeu(void);
void	libere_jeu(void);
int		taille_max(int c, int l);
int		lire_jeu_2(int fd);
int		lire_jeu_1_2(char *name);
int		lire_jeu_2_n(int fd);
int		lire_jeu(char *name);
void	affiche(void);

#endif
