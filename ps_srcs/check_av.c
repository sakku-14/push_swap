#include "../includes/push_swap.h"

int
	check_av(int ac, char **av)
{
	int i;
	int len;

	i = 1;
	while (i < ac)
	{
		len = 0;
		while (av[i][len])
		{
			if (av[i][len] == '-' || av[i][len] == '+')
				len++;
			if (!(ft_isdigit(av[i][len++])))
				return (print_error());
		}
		i++;
	}
	return (TRUE);
}