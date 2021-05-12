#include "../includes/push_swap.h"

int
	check_three_asc(t_stacks *st)
{
	int		i;
	int		counter;
	t_dlist	*ptr;

	i = 0;
	while (st->nums[i] != st->a.head->num)
		i++;
	counter = 0;
	ptr = st->a.head;
	while (counter != 3)
	{
		if (i == st->len)
			i = 0;
		if (ptr->num == st->nums[i])
			counter++;
		else
			return (FALSE);
		if (ptr != st->a.tail)
			ptr = ptr->next;
		i++;
	}
	return (TRUE);
}

int
	ra_need(t_stacks *st, int num)
{
	int		head;
	t_dlist	*ptr;

	head = 0;
	ptr = st->a.head;
	while (st->nums[0] != ptr->num)
	{
		ptr = ptr->next;
		head++;
	}
	if (head <= num / 2)
		return (TRUE);
	return (FALSE);
}

void
	sort_three(t_stacks *st)
{
	if (check_three_asc(st) == FALSE)
	{
		swap(&st->a);
		//write(1, "sa\n", 3);
		if (add_oper(st, 1) == FALSE)
			exit_error();
	}
	if (check_stack_a(st) == FALSE)
	{
		if (ra_need(st, 3) == TRUE)
		{
			rotate(&st->a);
			//write(1, "ra\n", 3);
			if (add_oper(st, 6) == FALSE)
				exit_error();
		}
		else
		{
			rev_rotate(&st->a);
			//write(1, "rra\n", 4);
			if (add_oper(st, 9) == FALSE)
				exit_error();
		}
	}
}
