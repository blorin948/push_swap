#include "push_swap.h"

int	get_min(int *tab, int size)
{
	int	i;
	int	min;

	i = 0;
	min = tab[0];
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int	get_max(int *tab, int size)
{
	int	i;
	int	max;

	i = 0;
	max = tab[0];
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

void	put_top(t_nbr *s, int nb)
{
	int	i;
	int	med;

	i = 0;
	med = s->sizea / 2;
	while (s->taba[i] != nb)
		i++;
	if (i < med)
	{
		while (s->taba[0] != nb)
			ra(s);
	}
	else
	{
		while (s->taba[0] != nb)
			rra(s);
	}
}

void	put_top_b(t_nbr *s, int nb)
{
	int	i;
	int	med;

	i = 0;
	med = s->sizeb / 2;
	while (s->tabb[i] != nb)
		i++;
	if (i < med)
	{
		while (s->tabb[0] != nb)
			rb(s);
	}
	else
	{
		while (s->tabb[0] != nb)
			rrb(s);
	}
}

void	move_b(t_nbr *s)
{
	int	max;
	int	min;

	max = get_max(s->tabb, s->sizeb);
	min = get_min(s->tabb, s->sizeb);
	if (s->taba[0] > max)
		put_top_b(s, min);
	else if (s->taba[0] < min)
		put_top_b(s, max);
	pb(s);
}
