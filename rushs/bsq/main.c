/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:53:58 by anporced          #+#    #+#             */
/*   Updated: 2023/09/12 18:54:01 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "carre.h"

t_jeu	g_jeu;

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	g_jeu.nb_col = 1;
	if (argc == 1)
		jouer(NULL);
	while (i < argc)
		jouer(argv[i++]);
	return (0);
}
