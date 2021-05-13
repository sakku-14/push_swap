#include "../includes/push_swap.h"

static void
	q_sort_stack_first_sp(t_stacks *st)
{
	push(st, 'b');
	if (add_oper(st, 5) == FALSE)
		exit_error();
	rotate(&st->b);
	if (add_oper(st, 7) == FALSE)
		exit_error();
}

static void
	q_sort_stack_first_norm(t_stacks *st)
{
	push(st, 'b');
	if (add_oper(st, 5) == FALSE)
		exit_error();
}

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
			if (st->a.head->num <= st->nums[3] && st->b.head->exist != 0)
				q_sort_stack_first_sp(st);
			else
				q_sort_stack_first_norm(st);
		}
		else
		{
			rotate(&(st->a));
			if (add_oper(st, 6) == FALSE)
				exit_error();
		}
		counter++;
	}
}
