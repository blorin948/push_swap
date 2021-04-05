#include "push_swap.h"

void	rb(t_nbr *s)
{
	int	start;
	int	i;

	start = s->tabb[0];
	i = 0;
	if (s->print)
		printf("rb\n");
	if (s->sizeb < 2)
		return ;
	while (i < s->sizeb - 1)
	{
		s->tabb[i] = s->tabb[i + 1];
		i++;
	}
	s->tabb[i] = start;
}

void	rr(t_nbr *s)
{
	if (s->print)
		printf("rr\n");
	rb(s);
	ra(s);
}

void	rra(t_nbr *s)
{
	int	last;
	int	i;

	last = s->taba[s->sizea - 1];
	i = s->sizea - 1;
	if (s->print)
		printf("rra\n");
	if (s->sizea < 2)
		return ;
	while (i > 0)
	{
		s->taba[i] = s->taba[i - 1];
		i--;
	}
	s->taba[0] = last;
}

void	rrb(t_nbr *s)
{
	int	last;
	int	i;

	last = s->tabb[s->sizeb - 1];
	i = s->sizeb - 1;
	if (s->print)
		printf("rrb\n");
	if (s->sizeb < 2)
		return ;
	while (i > 0)
	{
		s->tabb[i] = s->tabb[i - 1];
		i--;
	}
	s->tabb[0] = last;
}

void	rrr(t_nbr *s)
{
	if (s->print)
		printf("rrr\n");
	rra(s);
	rrb(s);
}
