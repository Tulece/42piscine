/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anporced <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:42:42 by anporced          #+#    #+#             */
/*   Updated: 2023/09/14 23:04:58 by anporced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;
	
	i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	while (i < n)
		i++;
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	int		wc;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i])
			wc++;
		while (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
			i++
	}
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		while (str[i] != ' ' || str[i] != '\t' || str[i] != '\n')
			i++
	}
	if (i > j)
	{
		tab[k] = malloc(sizeof(char) * (i - j) + 1);
		ft_strncpy(tab[k++], &str[i], i - j);
	}
	tab[k] == NULL;
	return (tab);
}
