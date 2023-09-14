/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:20:15 by anporced          #+#    #+#             */
/*   Updated: 2023/09/13 17:37:08 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i = 0;
	int	start;
	int	end;
	int	flag = 0;
	if (ac > 1 && av[1][0])
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		start = i;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			i++;
		end = i;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			while (av[1][i] == ' ' && av[1][i + 1] == ' ' || av[1][i] == '\t' && av[1][i + 1] == '\t')
				i++;
			if (av[1][i] == ' ' || av[1][i] == '\t')
				flag = 1;
			write(1, &av[1][i], 1);
			i++;
		}	
		if (flag)
			write(1, " ", 1);
		while (start < end)
		{
			write(1, &av[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
}

// "  Que	 la 	lumiere soit et la lumiere fut  "
