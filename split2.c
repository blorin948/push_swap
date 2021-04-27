#include "push_swap.h"

char	**ft_split2(char **copy, int ac, t_nbr *s)
{
	int		i;
	char	**tmp;
	char	**new;

	i = 0;
	if (is_space(copy[0]) == 0)
	{
		init_nbr(s, ac);
		return (copy);
	}
	tmp = copy;
	new = ft_split(copy[0], ' ');
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	ac = 0;
	while (new[ac])
		ac++;
	init_nbr(s, ac);
	i = 0;
	return (new);
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
