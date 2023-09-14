/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:53:38 by anporced          #+#    #+#             */
/*   Updated: 2023/09/14 13:51:45 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_doubles(char *str, char c, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int			i;
	char		*s1;
	char		*s2;

	i = 0;
	s1 = av[1];
	s2 = av[2];
	if (ac == 3)
	{
		while (s1[i])
		{
			if (!check_doubles(s1, s1[i], i))
				write(1, &s1[i], 1);
			i++;
		}
		i = 0;
		while (s2[i])
		{
			if (!check_doubles(s2, s2[i], i) && !check_doubles(s1, s2[i], i))
				write(1, &s2[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
