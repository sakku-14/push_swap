#include "../includes/checker.h"

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
			if (!(ft_isdigit(av[i][len++])))
				return (print_error());
		}
		i++;
	}
	return (TRUE);
}

int
	check_stack_a(t_stacks *st)
{
	int		num;
	t_dlist	*ptr;

	if (st->len == 1)
		return (TRUE);
	num = st->a.head->num;
	ptr = st->a.head->next;
	while (ptr != st->a.head)
	{
		if (num > ptr->num)
			return (FALSE);
		num = ptr->num;
		ptr = ptr->next;
	}
	return (TRUE);
}

int
	check_stack(t_stacks *st)
{
	if (st->b.head->exist == 1)
		return (FALSE);
	if (check_stack_a(st) == FALSE)
		return (FALSE);
	return (TRUE);
}

int
	check_duplicate(t_stacks *st)
{
	int i;

	i = 0;
	while (i < st->len - 1)
	{
		if (st->nums[i] == st->nums[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}