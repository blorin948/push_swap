#include "push_swap.h"
#include "get_next_line.h"

int	check_double(t_nbr *s)
{
	int	i;
	int	val;
	int	a;

	i = 0;
	while (i < s->sizea)
	{
		val = s->taba[i];
		a = 0;
		while (a < s->sizea)
		{
			if (s->taba[a] == val && a != i)
				return (0);
			a++;
		}
		i++;
	}
	return (1);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (0);
	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atoi(const char *nptr)
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
