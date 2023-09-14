/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:48:41 by anporced          #+#    #+#             */
/*   Updated: 2023/08/27 13:16:14 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	shape_0(char *shape);
void	shape_1(char *shape);
void	shape_2(char *shape);
void	shape_3(char *shape);
void	shape_4(char *shape);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int x, char end, char mid, char start)
{
	int	ix;

	ix = 0;
	if (x <= 1)
	{
		ft_putchar(start);
		return ;
	}
	while (ix <= x)
	{
		if (ix == 0)
			ft_putchar(start);
		else if (ix == x)
			ft_putchar(end);
		else
			ft_putchar(mid);
		ix++;
	}
}

void	profile_to_shape(int profile, char *shape)
{
	if (profile == 0)
		shape_0(shape);
	if (profile == 1)
		shape_1(shape);
	if (profile == 2)
		shape_2(shape);
	if (profile == 3)
		shape_3(shape);
	if (profile == 4)
		shape_4(shape);
	shape[9] = '\0';
}

void	rush(int x, int y, int profile)
{
	int		iy;
	char	shape[9];

	if ((x > 0) & (y > 0) & (profile >= 0) & (profile < 5))
	{
		profile_to_shape(profile, shape);
		iy = 1;
		while (iy <= y)
		{
			if (iy == 1)
				ft_print(x, shape[0], shape[1], shape[2]);
			else if (iy == y)
				ft_print(x, shape[3], shape[4], shape[5]);
			else
				ft_print(x, shape[6], shape[7], shape[8]);
			iy++;
			ft_putchar('\n');
		}
	}
	else
	{
		write(2, "error, input value(s) not accepted\n", 35);
	}
}
