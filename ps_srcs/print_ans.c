#include "../includes/push_swap.h"

void
	print_each(t_dlist *ptr)
{
	if (ptr->num == 1)
		write(1, "sa\n", 3);
	else if (ptr->num == 2)
		write(1, "sb\n", 3);
	else if (ptr->num == 3)
		write(1, "ss\n", 3);
	else if (ptr->num == 4)
		write(1, "pa\n", 3);
	else if (ptr->num == 5)
		write(1, "pb\n", 3);
	else if (ptr->num == 6)
		write(1, "ra\n", 3);
	else if (ptr->num == 7)
		write(1, "rb\n", 3);
	else if (ptr->num == 8)
		write(1, "rr\n", 3);
	else if (ptr->num == 9)
		write(1, "rra\n", 4);
	else if (ptr->num == 10)
		write(1, "rrb\n", 4);
	else if (ptr->num == 11)
		write(1, "rrr\n", 4);
}

void
	print_ans(t_stacks *st)
{
	t_dlist	*ptr;

	ptr = st->ans_def.head->next;
	while (ptr != st->ans_def.tail)
	{
		print_each(ptr);
		ptr = ptr->next;
	}
	print_each(ptr);
}
