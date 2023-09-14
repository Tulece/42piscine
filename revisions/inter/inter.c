/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:52:40 by anporced          #+#    #+#             */
/*   Updated: 2023/09/14 15:07:46 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check(char *str, char c, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int			i;
	int			j;
	char		*s1;
	char		*s2;

	i = 0;
	s1 = av[1];
	s2 = av[2];
	if (ac == 3)
	{
		while (s1[i])
		{
			j = 0;
			while (s2[j])
			{
				if (s1[i] == s2[j] && !check(s1, s1[i], i))
					write(1, &s1[i++], 1);
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
