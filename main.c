#include "push_swap.h"


int		ft_atoi(const char *nptr)
{
	int				i;
	int				signe;
	long long		nb;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	signe = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	nb = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * signe);
}

void    print_list(t_nbr *s)
{
    int a = 0;
    printf("Pile A		Pile B\n");
    while (a < s->sizea || a < s->sizeb)
    {
        if (a < s->sizea  && a < s->sizeb)
            printf("%d		%d\n", s->taba[a], s->tabb[a]);
        else if(a < s->sizea)
            printf("%d\n", s->taba[a]);
        else if(a < s->sizeb)
            printf("		%d\n", s->tabb[a]);
        a++;
    }
}


int get_min(t_nbr *s)
{
	int i = 0;
	int min = s->taba[0];

	while (i < s->sizea)
	{
		if (s->taba[i] < min)
			min = s->taba[i];
		i++;
	}
	return (min);
}


int get_max(t_nbr *s)
{
	int i = 0;
	int max = s->taba[0];

	while (i < s->sizea)
	{
		if (s->taba[i] > max)
			max = s->taba[i];
		i++;
	}
	return (max);
}

void three_nbr(t_nbr *s)
{
	int min = get_min(s);
	int max = get_max(s);
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



int main(int ac, char **av)
{
	t_nbr *s;
	s = malloc(sizeof(t_nbr));
	s->sizea = ac - 1;
	s->sizeb = 0;
	int i = 1;
	int a = 0;
	int nb;
	s->taba = malloc(sizeof(int) * ac - 1);
	s->tabb = malloc(sizeof(int));
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		s->taba[a] = nb;
		i++;
		a++;
	}
	if (ac == 4)
		three_nbr(s);
	print_list(s);
}