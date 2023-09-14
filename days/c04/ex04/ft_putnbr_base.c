/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:25:33 by anporced          #+#    #+#             */
/*   Updated: 2023/08/30 21:31:35 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	has_double_char(char *baseb)
{
	int	a;
	int	b;

	a = 0;
	while (baseb[a] != '\0')
	{
		b = a + 1;
		while (baseb[b] != '\0')
		{
			if (baseb[a] == baseb[b])
				return (1);
			++b;
		}
		a++;
	}
	return (0);
}

void	print_nbr(int n, int sizeb, char *baseb)
{
	long	original_num;

	original_num = n;
	if (original_num < 0)
	{
		ft_putchar('-');
		original_num = -original_num;
	}
	if (original_num >= sizeb)
		print_nbr(original_num / sizeb, sizeb, baseb);
	ft_putchar(baseb[original_num % sizeb]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	sizeb;

	sizeb = 0;
	while (base[sizeb] != '\0')
	{
		if (base[sizeb] == '+' || base[sizeb] == '-' 
			|| (base[sizeb] >= 9 && base[sizeb] <= 13)
			|| base[sizeb] == 32)
			return ;
		sizeb++;
	}
	if (sizeb <= 1)
		return ;
	if (has_double_char(base))
		return ;
	print_nbr(nbr, sizeb, base);
}
