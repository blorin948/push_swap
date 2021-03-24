#include "push_swap.h"

t_nbr *pa(t_nbr *s)
{
	s->nb_instru++;
	printf("pa\n");
	int *newa;
	int *newb;
	if (s->sizeb == 0)
		return  s;
	newa = malloc(sizeof(int) * s->sizea + 1);
	newb = malloc(sizeof(int) * s->sizeb - 1);
	int i = 0;
	int a = 1;
	newa[0] = s->tabb[0];
	while (i < s->sizea)
	{
		newa[a] = s->taba[i];
		i++;
		a++;
	}
	i = 1;
	a = 0;
	while (i < s->sizeb)
	{
		newb[a] = s->tabb[i];
		i++;
		a++;
	}
	free(s->taba);
	s->taba = newa;
	free(s->tabb);
	s->tabb = newb;
	s->sizea = s->sizea + 1;
	s->sizeb = s->sizeb - 1;
	return (s);
}

t_nbr *pb(t_nbr *s)
{
	s->nb_instru++;
	printf("pb\n");
	int *newa;
	int *newb;
	if (s->sizea == 0)
		return  s;
	newb = malloc(sizeof(int) * s->sizeb + 1);
	newa = malloc(sizeof(int) * s->sizea - 1);
	int i = 0;
	int a = 1;
	newb[0] = s->taba[0];
	while (i < s->sizeb)
	{
		newb[a] = s->tabb[i];
		i++;
		a++;
	}
	i = 1;
	a = 0;
	while (i < s->sizea)
	{
		newa[a] = s->taba[i];
		i++;
		a++;
	}
	free(s->taba);
	s->taba = newa;
	free(s->tabb);
	s->tabb = newb;
	s->sizea = s->sizea - 1;
	s->sizeb = s->sizeb + 1;
	return (s);
}

t_nbr *sa(t_nbr *s)
{
	s->nb_instru++;
	printf("sa\n");
	if (s->sizea < 2)
		return s;
	int tmp;
	tmp = s->taba[1];
	s->taba[1] = s->taba[0];
	s->taba[0] = tmp;
	return (s);
}

t_nbr *sb(t_nbr *s)
{
	s->nb_instru++;
	printf("sb\n");
	if (s->sizeb < 2)
		return s;
	int tmp;
	tmp = s->tabb[1];
	s->tabb[1] = s->tabb[0];
	s->tabb[0] = tmp;
	return (s);
}

void ss(t_nbr *s)
{
	printf("ss\n");
	sa(s);
	sb(s);
}

void ra(t_nbr *s)
{
	s->nb_instru++;
	int start = s->taba[0];
	int i = 0;
printf("ra\n");
	if (s->sizea < 2)
	{
		return;
	}
	while (i < s->sizea - 1)
	{
		s->taba[i] = s->taba[i + 1];
		i++;
	}
	s->taba[i] = start;
}

void rb(t_nbr *s)
{
	s->nb_instru++;
	printf("rb\n");
	int start = s->tabb[0];
	int i = 0;
	if (s->sizeb < 2)
		return ;
	while (i < s->sizeb - 1)
	{
		s->tabb[i] = s->tabb[i + 1];
		i++;
	}
	s->tabb[i] = start;
}

void rr(t_nbr *s)
{
	printf("rr\n");
	rb(s);
	ra(s);
}

void rra(t_nbr *s)
{
	s->nb_instru++;
	printf("rra\n");
	if (s->sizea < 2)
		return ;
	int last = s->taba[s->sizea - 1];
	int tmp;
	int i = s->sizea - 1;
	while (i > 0)
	{
		s->taba[i] = s->taba[i - 1];
		i--;
	}
	s->taba[0] = last;
}

void rrb(t_nbr *s)
{
	s->nb_instru++;
	printf("rrb\n");
	if (s->sizeb < 2)
		return ;
	int last = s->tabb[s->sizeb - 1];
	int tmp;
	int i = s->sizeb - 1;
	while (i > 0)
	{
		s->tabb[i] = s->tabb[i - 1];
		i--;
	}
	s->tabb[0] = last;
}

void rrr(t_nbr *s)
{
	printf("rrr\n");
	rra(s);
	rrb(s);
}