#include "push_swap.h"

void	three_nbr(t_nbr *s)
{
	int	min;
	int	max;

	min = get_min(s->taba, s->sizea);
	max = get_max(s->taba, s->sizea);
	if (s->taba[1] == min && s->taba[2] == max)
		sa(s);
	else if (s->taba[0] == max && s->taba[2] == min)
	{
		sa(s);
		rra(s);
	}
	else if (s->taba[0] == max && s->taba[1] == min)
		ra(s);
	else if (s->taba[0] == min && s->taba[1] == max)
	{
		sa(s);
		ra(s);
	}
	else if (s->taba[1] == max && s->taba[2] == min)
		rra(s);
}

void	five_nbr(t_nbr *s)
{
	int	min;

	min = get_min(s->taba, s->sizea);
	while (s->sizea > 3)
	{
		min = get_min(s->taba, s->sizea);
		put_top(s, min);
		pb(s);
	}
	three_nbr(s);
	while (s->sizeb > 0)
		pa(s);
}
