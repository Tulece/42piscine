/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:24:39 by anporced          #+#    #+#             */
/*   Updated: 2023/08/29 14:25:05 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	caps;

	ft_strlowcase(str);
	i = 0;
	caps = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			caps = 0;
		if (caps == 1 && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
			caps = 0;
		}
		if (!(str[i] >= 'a' && str[i] <= 'z')
			&&!(str[i] >= 'A' && str[i] <= 'Z')
			&&!(str[i] >= '0' && str[i] <= '9'))
			caps = 1;
		i++;
	}
	return (str);
}
