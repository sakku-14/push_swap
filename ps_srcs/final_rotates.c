#include "../includes/push_swap.h"

void
	final_rotates(t_stacks *st)
{
	while (check_stack_a(st) == FALSE)
	{
		if (ra_need(st, 5) == TRUE)
		{
			rotate(&st->a);
			write(1, "ra\n", 3);
		}
		else
		{
			rev_rotate(&st->a);
			write(1, "rra\n", 4);
		}
	}
}
