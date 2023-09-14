/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:38:04 by anporced          #+#    #+#             */
/*   Updated: 2023/08/31 15:43:11 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc - 1;
	while (i > 0)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, argv[i] + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_rev_params(argc, argv);
	return (0);
}
