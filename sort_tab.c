#include "push_swap.h"

void	sort(int *tab, int size)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	tmp = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	split_tab(t_nbr *s, int nbr)
{
	int	*tab;
	int	tmp;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * s->sizea);
	while (i < s->sizea)
	{
		tab[i] = s->taba[i];
		i++;
	}
	sort(tab, s->sizea);
	if (s->sizea < nbr)
		tmp = get_max(tab, s->sizea);
	else
		tmp = tab[nbr - 1];
	free(tab);
	return (tmp);
}

int	is_sorted(t_nbr *s)
{
	int	i;

	if (s->sizeb != 0)
		return (0);
	i = 0;
	while (i < s->sizea - 1)
	{
		if (s->taba[i] > s->taba[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_list(t_nbr *s)
{
	int	a;

	a = 0;
	printf("Pile A		Pile B\n");
	while (a < s->sizea || a < s->sizeb)
	{
		if (a < s->sizea && a < s->sizeb)
			printf("%d		%d\n", s->taba[a], s->tabb[a]);
		else if (a < s->sizea)
			printf("%d\n", s->taba[a]);
		else if (a < s->sizeb)
			printf("		%d\n", s->tabb[a]);
		a++;
	}
	printf("instruction = %d\n", s->nb_instru);
}
