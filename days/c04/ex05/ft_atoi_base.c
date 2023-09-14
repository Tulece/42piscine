/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:52:30 by anporced          #+#    #+#             */
/*   Updated: 2023/08/30 21:21:42 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_unique_chars(char *str)
{
	int	char_flags[256];
	int	i;
	int	ascii_value;

	if (str == NULL)
		return (0);
	i = 0;
	while (i < 256)
	{
		char_flags[i] = 0;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		ascii_value = (int)str[i];
		if (char_flags[ascii_value])
			return (0);
		if (ascii_value < 32 || ascii_value > 126)
			return (0);
		char_flags[ascii_value] = 1;
		i++;
	}
	return (1);
}

int	is_in_base(char c, char *base)
{
	while (base[0])
	{
		if (base[0] == c)
			return (1);
		base++;
	}
	return (0);
}

int	char_to_base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	signs(char *str, int i, int *sign_multiplier)
{
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign_multiplier *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign_multiplier;
	int	result;
	int	i;
	int	base_length;

	sign_multiplier = 1;
	i = 0;
	result = 0;
	base_length = 0;
	if (!is_valid_unique_chars(base))
		return (0);
	while (base[base_length])
		base_length++;
	while (((str[i] >= 9) && (str[i] <= 13)) || str[i] == 32)
	{
		i++;
	}
	i = signs(str, i, &sign_multiplier);
	while (is_in_base(str[i], base))
	{
		result = result * base_length + char_to_base_index(str[i], base);
		i++;
	}
	result *= sign_multiplier;
	return (result);
}
