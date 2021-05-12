#include "../includes/push_swap.h"

void
	q_sort_stack_a(t_stacks *st)
{
	int	group;

	group = st->a.head->group;
	while (st->a.head->group == group && st->a.head->num != st->nums[0])
	{
		push(st, 'b');
		//write(1, "pb\n", 3);
		if (add_oper(st, 5) == FALSE)
			exit_error();
		set_sorted(st);
	}
}
