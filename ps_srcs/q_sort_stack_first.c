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
			push(st, 'b');
			//write(1, "pb\n", 3);
			if (add_oper(st, 5) == FALSE)
				exit_error();
			//TODO: check below
			if (st->b.head->num <= st->nums[3] && st->b.head != st->b.tail)
			{
				rotate(&st->b);
				if (add_oper(st, 7) == FALSE)
					exit_error();
				counter++;
			}
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
