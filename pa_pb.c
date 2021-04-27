#include "push_swap.h"

void	free_all(t_nbr *s, char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
		free(copy[i++]);
	free(copy);
	free(s->taba);
	free(s->tabb);
	free(s);
}

void	pa2(t_nbr *s, int *newa, int *newb)
{
	free(s->taba);
	s->taba = newa;
	free(s->tabb);
	s->tabb = newb;
	s->sizea = s->sizea + 1;
	s->sizeb = s->sizeb - 1;
}

t_nbr	*pa(t_nbr *s)
{
	int	*newa;
	int	*newb;
	int	i;

	i = 0;
	if (s->print)
		printf("pa\n");
	if (s->sizeb == 0)
		return (s);
	newa = malloc(sizeof(int) * s->sizea + 1);
	newb = malloc(sizeof(int) * s->sizeb - 1);
	newa[0] = s->tabb[0];
	while (i < s->sizea)
	{
		newa[i + 1] = s->taba[i];
		i++;
	}
	i = 0;
	while (i + 1 < s->sizeb)
	{
		newb[i] = s->tabb[i + 1];
		i++;
	}
	pa2(s, newa, newb);
	return (s);
}

void	pb2(t_nbr *s, int *newa, int *newb)
{
	free(s->taba);
	s->taba = newa;
	free(s->tabb);
	s->tabb = newb;
	s->sizea = s->sizea - 1;
	s->sizeb = s->sizeb + 1;
}

t_nbr	*pb(t_nbr *s)
{
	int	*newa;
	int	*newb;
	int	i;

	i = 0;
	if (s->print)
		printf("pb\n");
	if (s->sizea == 0)
		return (s);
	newb = malloc(sizeof(int) * s->sizeb + 1);
	newa = malloc(sizeof(int) * s->sizea - 1);
	newb[0] = s->taba[0];
	while (i < s->sizeb)
	{
		newb[i + 1] = s->tabb[i];
		i++;
	}
	i = 0;
	while (i + 1 < s->sizea)
	{
		newa[i] = s->taba[i + 1];
		i++;
	}
	pb2(s, newa, newb);
	return (s);
}
