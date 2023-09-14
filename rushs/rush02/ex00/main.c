/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalbeck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:25:27 by tmalbeck          #+#    #+#             */
/*   Updated: 2023/09/10 21:10:03 by tmalbeck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_is_valid_argc(int ac)
{
	if (ac < 2)
	{
		ft_error("\e[31mError:\e[0m Too few arguments... ");
		ft_error("You need to use \e[33mat least one\e[0m.\n");
		return (0);
	}
	if (ac > 3)
	{
		ft_error("\e[31mError:\e[0m Too much arguments... ");
		ft_error("You need to use \e[33m2 arguments\e[0m max.\n");
		return (0);
	}
	return (1);
}

int	ft_is_valid_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_error("\e[31mError:\e[0m Make sure you entered a");
			ft_error("\e[33m positive number\e[0m !\n");
			return (0);
		}
		i++;
	}
	if (str[0] == '0' && str[1] == '0')
	{
		ft_error("\e[31mError:\e[0m Make sure to");
		ft_error("\e[33m put only one zero\e[0m.\n");
		return (0);
	}
	if (i > 39)
	{
		ft_error("\e[31mError:\e[0m Number size \e[33mtoo large\e[0m.\n");
		return (0);
	}
	return (1);
}

void	ft_is_zero(char *str, char **dict)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] == '0')
	{
		i++;
	}
	if (str[i] == '\0')
	{
		i = 0;
		while (dict[i])
		{
			if (dict[i][0] == '0')
			{
				ft_putstr(dict[i + 1]);
			}
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	char	**dict;

	if (!ft_is_valid_argc(ac))
		return (-1);
	if ((ac == 2 && !ft_is_valid_argv(av[1]))
		|| (ac == 3 && !ft_is_valid_argv(av[2])))
		return (-1);
	if (ac == 2)
	{
		dict = ft_get_dict_content("numbers.dict");
		if (!ft_check_dict(dict))
			return (-1);
		ft_is_zero(av[1], dict);
		ft_display(av[1], dict);
	}
	if (ac == 3)
	{
		dict = ft_get_dict_content(av[1]);
		if (!ft_check_dict(dict))
			return (-1);
		ft_is_zero(av[2], dict);
		ft_display(av[2], dict);
	}
	ft_free(dict);
	return (0);
}
