#include "../includes/push_swap.h"

void
	q_sort_stack_first(t_stacks *st)
{
	int	pivot;
	int	counter;

	pivot = st->nums[(st->len - 1) / 2];
	counter = 0;
	while (counter < st->len)
	{
		if (st->a.head->num <= pivot)
		{
			//just try
			/*
			if (st->a.head->num <= st->nums[3] && st->b.head->exist != 0)
			{
				push(st, 'b');
				if (add_oper(st, 5) == FALSE)
					exit_error();
				rotate(&st->b);
				if (add_oper(st, 7) == FALSE)
					exit_error();
			}
			else
			{
				push(st, 'b');
				if (add_oper(st, 5) == FALSE)
					exit_error();
			}
			*/
			//default
			push(st, 'b');
			if (add_oper(st, 5) == FALSE)
				exit_error();
		}
		else
		{
			rotate(&(st->a));
			//write(1, "ra\n", 3);
			if (add_oper(st, 6) == FALSE)
				exit_error();
		}
		counter++;
	}
}
