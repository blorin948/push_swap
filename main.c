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
	s->sizea = ac;
	s->sizeb = 0;
	s->print = 1;
	s->nb_instru = 0;
	s->taba = malloc(sizeof(int) * ac);
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
		{
			error();
		}
		nb = ft_atoi(av[i]);
		if (nb > 2147483647 || nb < -2147483648)
			error();
		s->taba[a++] = nb;
		i++;
	}
}



char **ft_split2(char **copy, int ac, t_nbr *s)
{
	int i = 0;
	char **tmp;
	char **new;

	if (is_space(copy[0]) == 0)
	{
		init_nbr(s, ac);
		return (copy);
	}
	tmp = copy;
	new = ft_split(copy[0], ' ');
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
		ac = 0;
		while (new[ac])
			ac++;
		init_nbr(s, ac);
		i = 0;
	return (new);
}

int	main(int ac, char **av)
{
	t_nbr		*s;
	int			i;
	int			c;
	char **copy;

	c = 0;
	i = 0;
	s = malloc(sizeof(t_nbr));
	copy = copy_tab(av, ac);
	ac = ac - 1;
	if (ac == 1)
	{
		copy = ft_split2(copy, ac, s);
		ac = 0;
		while (copy[ac])
			ac++;
	}
	else
		init_nbr(s, ac);
	init_tab(s, ac, copy, i);
	start_swap(s, ac);
	free_all(s, copy);
}
