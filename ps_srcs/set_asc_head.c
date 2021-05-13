#include "../includes/push_swap.h"

void
	set_pair_ra(t_stacks *st, int i)
{
	while (i > 0)
	{
		rotate(&st->a);
		if (add_oper(st, 6) == FALSE)
			exit_error();
		i--;
	}
}

void
	set_pair_rra(t_stacks *st, int i)
{
	while (i < 5)
	{
		rev_rotate(&st->a);
		if (add_oper(st, 9) == FALSE)
			exit_error();
		i++;
	}
}

void
	set_asc_head(t_stacks *st)
{
	int		i;
	t_dlist	*ptr;

	i = 0;
	ptr = st->a.head;
	while (i < 5)
	{
		if (asc_pres_next(st, ptr) == TRUE)
			break ;
		i++;
		ptr = ptr->next;
	}
	if (i < 3)
		set_pair_ra(st, i);
	else
		set_pair_rra(st, i);
}
