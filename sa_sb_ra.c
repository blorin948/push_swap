#include "push_swap.h"

t_nbr	*sa(t_nbr *s)
{
	int	tmp;

	if (s->print)
		printf("sa\n");
	if (s->sizea < 2)
		return (s);
	tmp = s->taba[1];
	s->taba[1] = s->taba[0];
	s->taba[0] = tmp;
	return (s);
}

t_nbr	*sb(t_nbr *s)
{
	int	tmp;

	if (s->print)
		printf("sb\n");
	if (s->sizeb < 2)
		return (s);
	tmp = s->tabb[1];
	s->tabb[1] = s->tabb[0];
	s->tabb[0] = tmp;
	return (s);
}

void	ss(t_nbr *s)
{
	if (s->print)
		printf("ss\n");
	sa(s);
	sb(s);
}

void	ra(t_nbr *s)
{
	int	start;
	int	i;

	start = s->taba[0];
	i = 0;
	if (s->print)
		printf("ra\n");
	if (s->sizea < 2)
		return ;
	while (i < s->sizea - 1)
	{
		s->taba[i] = s->taba[i + 1];
		i++;
	}
	s->taba[i] = start;
}
