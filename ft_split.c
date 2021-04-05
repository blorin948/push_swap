/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blorin <blorin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:14:09 by blorin            #+#    #+#             */
/*   Updated: 2021/04/01 15:40:25 by blorin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_tab(char const *s, char c, char **tab)
{
	int	a;
	int	i;
	int	j;

	a = 0;
	i = 0;
	j = 0;
	while (s[a] != '\0')
	{
		while (s[a] != '\0' && s[a] == c)
			a++;
		while (s[a] != '\0' && s[a] != c)
			tab[i][j++] = s[a++];
		if (j != 0)
			tab[i++][j] = '\0';
		j = 0;
	}
	tab[i] = 0;
	return (tab);
}

int	size(char const *s, char c)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (s[i] == c)
		i++;
	if (s[i] != '\0')
		size = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				size++;
		}
		if (s)
			i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		k;
	int		i;
	int		a;

	i = 0;
	k = 0;
	a = 0;
	tab = malloc(sizeof(char *) * (size(s, c) + 1));
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0' && s[i++] != '\0')
			k++;
		tab[a++] = malloc(sizeof(char) * (k + 1));
		k = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (ft_tab(s, c, tab));
}

void	error(void)
{
	printf("Error\n");
	exit(0);
}
