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

int
	set_sorted(t_stacks *st)
{
	char	flag;
	int		counter;

	counter = 0;
	while (wated_num(st, &flag) == TRUE && st->n_ptr < st->len)
	{
		if (flag == 'a')
		{
			rotate(&(st->a));
			st->a.tail->group = -1;
			//write(1, "ra\n", 3);
			if (add_oper(st, 6) == FALSE)
				exit_error();
		}
		else if (flag == 'b')
		{
			attach_tail(st);
			//write(1, "pa\nra\n", 6);
			if (add_oper(st, 4) == FALSE)
				exit_error();
			if (add_oper(st, 6) == FALSE)
				exit_error();
			counter++;
		}
		else if (flag == 'z')
		{
			rev_rotate(&st->b);
			if (add_oper(st, 10) == FALSE)
				exit_error();
			attach_tail(st);
			if (add_oper(st, 4) == FALSE)
				exit_error();
			if (add_oper(st, 6) == FALSE)
				exit_error();
			//counter++;
		}
		flag = '\0';
		st->n_ptr++;
	}
	return (counter);
}
