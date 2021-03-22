#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <limits.h>

typedef struct s_nbr
{
	int *taba;
	int *tabb;
	int sizea;
	int sizeb;
}				t_nbr;

t_nbr *pa(t_nbr *s);
t_nbr *pb(t_nbr *s);
t_nbr *sa(t_nbr *s);
t_nbr *sb(t_nbr *s);
void ss(t_nbr *s);
void ra(t_nbr *s);
void rr(t_nbr *s);
void rra(t_nbr *s);
void rrb(t_nbr *s);
void rrr(t_nbr *s);
void rb(t_nbr *s);
#endif