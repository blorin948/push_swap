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
	printf("instruction = %d\n", s->nb_instru);
}


int get_min(int *tab, int size)
{
	int i = 0;
	int min = tab[0];

	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}


int get_max(int *tab, int size)
{
	int i = 0;
	int max = tab[0];

	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

void sort(int *tab, int size)
{
	int i = 0;
	int tmp = 0;
	int j = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = tmp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int split_tab(t_nbr *s, int nbr)
{
	int *tab;
	int nb;
	int i = 0;
	tab = malloc(sizeof(int) * s->sizea);
	while (i < s->sizea)
	{
		tab[i] = s->taba[i];
		i++;
	}
	sort(tab, s->sizea);
	/*i = 0;
	while (i < s->sizea)
	{
		printf("la = %d\n", tab[i++]);
	}*/
	if (s->sizea < nbr)
		return (get_max(tab, s->sizea));
	return (tab[nbr - 1]);
}

void three_nbr(t_nbr *s)
{
	int min = get_min(s->taba, s->sizea);
	int max = get_max(s->taba, s->sizea);
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

void put_top(t_nbr *s, int nb)
{
	int i = 0;
	int med = s->sizea/2;
	while (s->taba[i] != nb)
		i++;
	if (i < med)
	{
		while (s->taba[0] != nb)
		{
			ra(s);
		}
	}
	else
	{
		while (s->taba[0] != nb)
		{
			rra(s);
		}
	}
}

void put_top_b(t_nbr *s, int nb)
{
	int i = 0;
	int med = s->sizeb/2;
	while (s->tabb[i] != nb)
		i++;
	if (i < med)
	{
		while (s->tabb[0] != nb)
		{
			rb(s);
		}
	}
	else
	{
		while (s->tabb[0] != nb)
		{
			rrb(s);
		}
	}
}


int find_fastest(t_nbr *s, int index)
{
		int i = 0;
	int med = s->sizea / 2;
	int ra = s->sizea;
	int rra = s->sizea;
	if (index <= med)
	{
		ra = index;
	}
	else
	{
		rra = s->sizea - index;
	}
	if (ra > rra)
		return (rra);
	else
		return (ra);
}

void transfer2(t_nbr *s, int move, int index)
{
	int med = s->sizea / 2;
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

void move_b(t_nbr *s)
{
	int max = get_max(s->tabb, s->sizeb);
	int min = get_min(s->tabb, s->sizeb);
	if (s->taba[0] > max)
	{
		put_top_b(s, min);
	}
	else if (s->taba[0] < min)
	{
		put_top_b(s, max);
	}
pb(s);
	
}

void transfer(t_nbr *s, int first, int last)
{
	int i = 0;
	int med = s->sizea / 2;
	int move1 = find_fastest(s, first);
	int move2 = find_fastest(s, last);
	int fin_move = move1;
	if (move2 < fin_move)
		fin_move = move2;
	if (move2 < move1)
		transfer2(s, move2, last);
	else
		transfer2(s, move1, first);
	move_b(s);
}

void hundread_nbr2(t_nbr *s, int min, int max)
{
	int i = 0;
	int a = 0;
	int first = 0;
	int last = 0;
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
//	printf("la = %d     %d\n", s->taba[first], s->taba[last]);
	transfer(s, first, last);
}

void move_back(t_nbr *s)
{
	int i = 0;
	int max;
	while (s->sizeb > 0)
	{
		max = get_max(s->tabb, s->sizeb);
		put_top_b(s, max);
		pa(s);
	}

}
void hundred_nbr(t_nbr *s, int nb)
{
	int i = 0;
	int min;
	int max;
	while (s->sizea > 0)
	{
		min = get_min(s->taba, s->sizea);
		max = split_tab(s, nb);
	//	printf("LA = MIN %d      MAX = %d\n", min, max);
		while (i < nb)
		{
			hundread_nbr2(s, min, max);
			i++;
		}
		i = 0;
	}
//	print_list(s);
	move_back(s);
}

void five_nbr(t_nbr *s)
{
	int min = get_min(s->taba, s->sizea);
	int i = 0;
	int nb;
	int med;
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

int main(int ac, char **av)
{
	t_nbr *s;
	s = malloc(sizeof(t_nbr));
	s->sizea = ac - 1;
	s->sizeb = 0;
	int i = 1;
	int a = 0;
	int nb;
	s->nb_instru = 0;
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
	else if (ac >= 5 && ac <= 20)
		five_nbr(s);
	else if (ac <= 101)
		hundred_nbr(s, 15);
	else
		hundred_nbr(s, 40);
	print_list(s);
}