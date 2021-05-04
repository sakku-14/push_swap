#include "../includes/checker.h"

int
	check_order(char *buf)
{
	if (ft_strlen(buf) == 2)
	{
		if (ft_strnstr(buf, "sa", 2) || ft_strnstr(buf, "sb", 2))
			return (TRUE);
		else if (ft_strnstr(buf, "ss", 2))
			return (TRUE);
		else if (ft_strnstr(buf, "pa", 2) || ft_strnstr(buf, "pb", 2))
			return (TRUE);
		else if (ft_strnstr(buf, "ra", 2) || ft_strnstr(buf, "rb", 2))
			return (TRUE);
		else if (ft_strnstr(buf, "rr", 2))
			return (TRUE);
	}
	else if (ft_strlen(buf) == 3)
	{
		if (ft_strnstr(buf, "rra", 3) || ft_strnstr(buf, "rrb", 3))
			return (TRUE);
		else if (ft_strnstr(buf, "rrr", 3))
			return (TRUE);
	}
	return (FALSE);
}

void
	do_order(t_stacks *st, char *buf)
{
	if (ft_strnstr(buf, "sa", 2))
		swap(&st->a);
	else if (ft_strnstr(buf, "sb", 2))
		swap(&st->b);
	else if (ft_strnstr(buf, "ss", 2))
		w_swap(st);
	else if (ft_strnstr(buf, "pa", 2))
		push(st, 'a');
	else if (ft_strnstr(buf, "pb", 2))
		push(st, 'b');
	else if (ft_strnstr(buf, "rra", 3))
		rev_rotate(&st->a);
	else if (ft_strnstr(buf, "rrb", 3))
		rev_rotate(&st->b);
	else if (ft_strnstr(buf, "rrr", 3))
		w_rev_rotate(st);
	else if (ft_strnstr(buf, "ra", 2))
		rotate(&st->a);
	else if (ft_strnstr(buf, "rb", 2))
		rotate(&st->b);
	else if (ft_strnstr(buf, "rr", 2))
		w_rotate(st);
}

int
	get_do_ord(t_stacks *st)
{
	int		ret;
	char	*buf;

	while (1)
	{
		ret = get_next_line(0, &buf);
		if (ret == 0)
			break ;
		if (ret < 0)
		{
			free(buf);
			return (FALSE);
		}
		if (check_order(buf) == FALSE)
		{
			free(buf);
			return (FALSE);
		}
		do_order(st, buf);
		free(buf);
		buf = NULL;
	}
	free(buf);
	return (TRUE);
}
