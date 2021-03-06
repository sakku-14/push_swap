#include "../includes/push_swap.h"

int
	min_is(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int
	ra_need_sub(t_stacks *st)
{
	int		i;
	int		min;
	t_dlist	*ptr;

	ptr = st->a.head;
	min = INT_MAX;
	while (ptr != st->a.tail)
	{
		min = min_is(min, ptr->num);
		ptr = ptr->next;
	}
	min = min_is(min, ptr->num);
	i = 0;
	ptr = st->a.head;
	while (ptr != st->a.tail)
	{
		if (ptr->num == min)
			break ;
		i++;
		ptr = ptr->next;
	}
	if (i < 2)
		return (TRUE);
	return (FALSE);
}

void
	set_three_asc(t_stacks *st)
{
	if (check_a_asc(st) == FALSE)
	{
		swap(&st->a);
		if (add_oper(st, 1) == FALSE)
			exit_error();
	}
	if (check_stack_a(st) == FALSE)
	{
		if (ra_need_sub(st) == TRUE)
		{
			rotate(&st->a);
			if (add_oper(st, 6) == FALSE)
				exit_error();
		}
		else
		{
			rev_rotate(&st->a);
			if (add_oper(st, 9) == FALSE)
				exit_error();
		}
	}
}
