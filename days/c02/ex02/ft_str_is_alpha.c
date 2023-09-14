/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:18:36 by anporced          #+#    #+#             */
/*   Updated: 2023/08/29 14:19:07 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (((str[i] >= 'a') && (str[i] <= 'z')) || \
					((str[i] >= 'A') && (str[i] <= 'Z')))
			i++;
		else
			return (0);
	}
	return (1);
}
/*#include <stdio.h>

int     main(int ac, char **ag)
{
         int 	i;

	 i = 0;
	 if (ac >= 2)
	 {
		 i = ft_str_is_alpha(ag[1]);
         	if (i == 0)
      	 printf("La chaine de caractere n'est pas qu'alaphabetique\n");
         	else if (i == 1)
                	 printf("C'est OK BG\n");
         	else
                	 printf("Il y a une couille dans le pate\n");
		return (0);
	 }
	 else
	 {
		 printf("Mets au moins 1 argument fdp\n");
		return (1);
	 }
}*/
