#include "../includes/push_swap.h"

void
	w_push(t_stacks *st, char to)
{
	push(st, to);
	push(st, to);
	if (to == 'b')
	{
		if (add_oper(st, 5) == FALSE)
			exit_error();
		if (add_oper(st, 5) == FALSE)
			exit_error();
	}
	else
	{
		if (add_oper(st, 4) == FALSE)
			exit_error();
		if (add_oper(st, 4) == FALSE)
			exit_error();
	}
}

void
	set_three(t_stacks *st)
{
	set_asc_head(st);
	w_push(st, 'b');
	set_three_asc(st);
	set_three_order(st);
	w_push(st, 'a');
}
