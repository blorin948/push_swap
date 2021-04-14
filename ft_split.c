/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blorin <blorin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:14:09 by blorin            #+#    #+#             */
/*   Updated: 2021/04/14 15:05:45 by blorin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char **copy_tab(char **av, int ac)
{
	char **copy;
	int i = 1;
	int a = 0;

	copy = malloc(sizeof(char *) * ac);
	while (i < ac)
	{
		copy[a] = ft_strdup(av[i]);
		a++;
		i++;
	}
	copy[a] = 0;
	return (copy);
}

int is_space(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

char    *ft_strdup(const char *src)
{
        char    *dest;
        int             i;

        i = 0;
        while (src[i] != '\0')
                i++;
        if (!(dest = malloc(sizeof(char) * (i + 1))))
                return (0);
        i = 0;
        while (src[i] != '\0')
        {
                dest[i] = (char)src[i];
                i++;
        }
        dest[i] = '\0';
        return (dest);
}

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
