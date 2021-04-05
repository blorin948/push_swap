#include "push_swap.h"

void	move_back(t_nbr *s)
{
	int	max;

	while (s->sizeb > 0)
	{
		max = get_max(s->tabb, s->sizeb);
		put_top_b(s, max);
		pa(s);
	}
}

void	init_nbr(t_nbr *s, int ac)
{
	s->sizea = ac - 1;
	s->sizeb = 0;
	s->print = 1;
	s->nb_instru = 0;
	s->taba = malloc(sizeof(int) * ac - 1);
	s->tabb = malloc(sizeof(int));
}

void	start_swap(t_nbr *s, int ac)
{
	if (!check_double(s))
	{
		printf("Error\n");
		exit(0);
	}
	if (is_sorted(s))
		return ;
	if (ac == 2)
		ra(s);
	else if (ac == 3)
		three_nbr(s);
	else if (ac >= 4 && ac <= 19)
		five_nbr(s);
	else if (ac <= 100)
		hundred_nbr(s, 15);
	else
		hundred_nbr(s, 40);
}

void	init_tab(t_nbr *s, int ac, char **av, int i)
{
	long long	nb;
	int			a;

	a = 0;
	while (i < ac)
	{
		if (ft_isdigit(av[i]) == 0)
			error();
		nb = ft_atoi(av[i]);
		if (nb > 2147483647 || nb < -2147483648)
			error();
		s->taba[a++] = nb;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_nbr		*s;
	int			i;
	int			c;

	c = 0;
	i = 1;
	s = malloc(sizeof(t_nbr));
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
		c++;
		ac = 0;
		while (av[ac])
			ac++;
		init_nbr(s, ac + 1);
	}
	else
		init_nbr(s, ac);
	init_tab(s, ac, av, i);
	if (c == 0)
		ac = ac - 1;
	start_swap(s, ac);
	free_all(s);
}
