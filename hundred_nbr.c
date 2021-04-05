#include "push_swap.h"

int	find_fastest(t_nbr *s, int index)
{
	int	i;
	int	med;
	int	ra;
	int	rra;

	i = 0;
	med = s->sizea / 2;
	ra = s->sizea;
	rra = s->sizea;
	if (index <= med)
		ra = index;
	else
		rra = s->sizea - index;
	if (ra > rra)
		return (rra);
	else
		return (ra);
}

void	transfer2(t_nbr *s, int move, int index)
{
	int	med;

	med = s->sizea / 2;
	if (index <= med)
	{
		while (move > 0)
		{
			ra(s);
			move--;
		}
	}
	else
	{
		while (move > 0)
		{
			rra(s);
			move--;
		}
	}
}

void	transfer(t_nbr *s, int first, int last)
{
	int	i;
	int	med;
	int	move1;
	int	move2;
	int	fin_move;

	i = 0;
	med = s->sizea / 2;
	move2 = find_fastest(s, last);
	move1 = find_fastest(s, first);
	fin_move = move1;
	if (move2 < fin_move)
		fin_move = move2;
	if (move2 < move1)
		transfer2(s, move2, last);
	else
		transfer2(s, move1, first);
	move_b(s);
}

void	hundread_nbr2(t_nbr *s, int max, int i)
{
	int	first;
	int	last;

	last = 0;
	while (i < s->sizea)
	{
		if (s->taba[i] <= max)
		{
			first = i;
			break ;
		}
		i++;
	}
	i = s->sizea - 1;
	while (i > 0)
	{
		if (s->taba[i] <= max)
		{
			last = i;
			break ;
		}
		i--;
	}
	transfer(s, first, last);
}

void	hundred_nbr(t_nbr *s, int nb)
{
	int	i;
	int	min;
	int	max;
	int	a;

	i = 0;
	a = 0;
	while (s->sizea > 0)
	{
		min = get_min(s->taba, s->sizea);
		max = split_tab(s, nb);
		while (i < nb)
		{
			hundread_nbr2(s, max, a);
			i++;
		}
		i = 0;
	}
	move_back(s);
}
