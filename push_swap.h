#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <limits.h>

typedef struct s_nbr
{
	int	*taba;
	int	*tabb;
	int	sizea;
	int	sizeb;
	int	print;
	int	nb_instru;
}				t_nbr;

t_nbr		*pa(t_nbr *s);
int			check_double(t_nbr *s);
int			split_tab(t_nbr *s, int nbr);
void		sort(int *tab, int size);
char		*ft_strdup(const char *src);
int			get_min(int *tab, int size);
int			get_max(int *tab, int size);
void		put_top_b(t_nbr *s, int nb);
void		put_top(t_nbr *s, int nb);
void		three_nbr(t_nbr *s);
void		free_all(t_nbr *s, char **copy);
int			is_space(char *str);
char		**copy_tab(char **av, int ac);
void		five_nbr(t_nbr *s);
void		hundred_nbr(t_nbr *s, int nb);
char		**ft_split2(char **copy, int ac, t_nbr *s);
void		move_b(t_nbr *s);
void		move_back(t_nbr *s);
t_nbr		*pb(t_nbr *s);
t_nbr		*sa(t_nbr *s);
int			ft_isdigit(char *str);
t_nbr		*sb(t_nbr *s);
void		ss(t_nbr *s);
int			is_sorted(t_nbr *s);
void		print_list(t_nbr *s);
void		init_nbr(t_nbr *s, int ac);
char		**ft_tab(char const *s, char c, char **tab);
int			ft_strcmp(char *str1, char *str2);
long long	ft_atoi(const char *nptr);
void		ra(t_nbr *s);
void		error(void);
void		rr(t_nbr *s);
void		rra(t_nbr *s);
void		rrb(t_nbr *s);
char		**ft_split(char const *s, char c);
void		rrr(t_nbr *s);
void		rb(t_nbr *s);
#endif