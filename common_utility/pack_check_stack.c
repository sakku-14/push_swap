#include "../includes/common_utility.h"

int
	check_over_int_range(char *str)
{
	long long int	num;
	int				flag;

	num = 0;
	flag = 0;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			flag = 1;
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
		if (num > 2147483647 && flag == 0)
			return (FALSE);
		if (num > 2147483648 && flag == 1)
			return (FALSE);
	}
	return (TRUE);
}

int
	pack_stack(t_stacks *st, char **av)
{
	int	num;
	int	i;

	if (check_over_int_range(av[1]) == FALSE)
		return (FALSE);
	num = ft_atoi(av[1]);
	ft_dlstnew(&st->a, num, 1);
	i = 2;
	while (i < st->len + 1)
	{
		if (check_over_int_range(av[i]) == FALSE)
			return (FALSE);
		num = ft_atoi(av[i]);
		if (ft_dlstadd_back(&st->a, num, 1) == FALSE)
			return (FALSE);
		i++;
	}
	if (build_stack_b(st) == FALSE)
		return (FALSE);
	return (TRUE);
}