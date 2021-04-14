#include "get_next_line.h"
#include "push_swap.h"

int	exec_cmd(char *line, t_nbr *s)
{
	if (ft_strcmp(line, "ra"))
		ra(s);
	else if (ft_strcmp(line, "rra"))
		rra(s);
	else if (ft_strcmp(line, "ss"))
		ss(s);
	else if (ft_strcmp(line, "pa"))
		pa(s);
	else if (ft_strcmp(line, "pb"))
		pb(s);
	else if (ft_strcmp(line, "rr"))
		rr(s);
	else if (ft_strcmp(line, "sa"))
		sa(s);
	else if (ft_strcmp(line, "sb"))
		sb(s);
	else if (ft_strcmp(line, "rb"))
		rb(s);
	else if (ft_strcmp(line, "rrb"))
		rrb(s);
	else if (ft_strcmp(line, "rrr"))
		rrr(s);
	else
		error();
	return (1);
}

void	init_nbr(t_nbr *s, int ac)
{
	s->sizea = ac;
	s->sizeb = 0;
	s->print = 0;
	s->nb_instru = 0;
	s->taba = malloc(sizeof(int) * ac);
	s->tabb = malloc(sizeof(int));
}

void	check2(t_nbr *s)
{
	char	*line;

	line = NULL;
	if (!check_double(s))
	{
		printf("Error\n");
		exit(0);
	}
	if (s->sizea == 0)
		return ;
	while (get_next_line(&line))
	{
		if (exec_cmd(line, s) == 0)
		{
			free(line);
			return ;
		}
		free(line);
	}
	free(line);
	if (is_sorted(s) == 1)
		printf("OK\n");
	else
		printf("KO\n");
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
	check2(s);
	free_all(s, copy);
}
