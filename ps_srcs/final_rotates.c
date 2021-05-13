#include "../includes/push_swap.h"

void
	final_rotates(t_stacks *st)
{
	while (check_stack_a(st) == FALSE)
	{
		if (ra_need(st, 5) == TRUE)
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
