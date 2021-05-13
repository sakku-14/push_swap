#include "../includes/push_swap.h"

int
	wated_num(t_stacks *st, char *flag)
{
	if (st->n_ptr >= st->len)
		return (FALSE);
	if (st->nums[st->n_ptr] == st->a.head->num)
	{
		*flag = 'a';
		return (TRUE);
	}
	else if (st->nums[st->n_ptr] == st->b.head->num)
	{
		*flag = 'b';
		return (TRUE);
	}
	else if (st->nums[st->n_ptr] == st->b.tail->num)
	{
		*flag = 'z';
		return (TRUE);
	}
	return (FALSE);
}

static void
	set_sorted_a(t_stacks *st)
{
	rotate(&(st->a));
	st->a.tail->group = -1;
	if (add_oper(st, 6) == FALSE)
		exit_error();
}

static void
	set_sorted_b(t_stacks *st, int *counter)
{
	attach_tail(st);
	if (add_oper(st, 4) == FALSE)
		exit_error();
	if (add_oper(st, 6) == FALSE)
		exit_error();
	(*counter)++;
}

static void
	set_sorted_z(t_stacks *st)
{
	rev_rotate(&st->b);
	if (add_oper(st, 10) == FALSE)
		exit_error();
	attach_tail(st);
	if (add_oper(st, 4) == FALSE)
		exit_error();
	if (add_oper(st, 6) == FALSE)
		exit_error();
}

int
	set_sorted(t_stacks *st)
{
	char	flag;
	int		counter;

	counter = 0;
	while (wated_num(st, &flag) == TRUE && st->n_ptr < st->len)
	{
		if (flag == 'a')
			set_sorted_a(st);
		else if (flag == 'b')
			set_sorted_b(st, &counter);
		else if (flag == 'z')
			set_sorted_z(st);
		flag = '\0';
		st->n_ptr++;
	}
	return (counter);
}
