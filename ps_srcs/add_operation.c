#include "../includes/push_swap.h"

int
	init_st_ans(t_stacks *st)
{
	if (ft_dlstnew(&st->ans_sub, 0, 1) == FALSE)
		return (FALSE);
	return (TRUE);
}

int
	add_oper(t_stacks *st, int oper)
{
	if (ft_dlstadd_back(&st->ans_sub, oper, 1) == FALSE)
		return (FALSE);
	return (TRUE);
}

int
	check_two_num(t_dlist *ptr, int a, int b)
{
	if (ptr->num == a && ptr->next->num == b)
		return (TRUE);
	else if (ptr->num == b && ptr->next->num == a)
		return (TRUE);
	return (FALSE);
}

int
	check_optimizeable(t_stacks *st, t_dlist *sub_ptr)
{
	if (check_two_num(sub_ptr, 4, 5) == TRUE)
		sub_ptr = sub_ptr->next->next;
	else if (check_two_num(sub_ptr, 6, 9) == TRUE)
		sub_ptr = sub_ptr->next->next;
	else if (check_two_num(sub_ptr, 7, 10) == TRUE)
		sub_ptr = sub_ptr->next->next;
	else if (check_two_num(sub_ptr, 8, 11) == TRUE)
		sub_ptr = sub_ptr->next->next;
	else if (check_two_num(sub_ptr, 1, 2) == TRUE)
	{
		if (ft_dlstadd_back(&st->ans_def, 3, 1))
			return (FALSE);
	}
	else if (check_two_num(sub_ptr, 6, 7) == TRUE)
	{
		if (ft_dlstadd_back(&st->ans_def, 8, 1))
			return (FALSE);
	}
	else if (check_two_num(sub_ptr, 9, 10) == TRUE)
	{
		if (ft_dlstadd_back(&st->ans_def, 11, 1))
			return (FALSE);
	}
	return (FALSE);
}

int
	optimize_ans(t_stacks *st)
{
	t_dlist	*sub_ptr;

	if (ft_dlstnew(&st->ans_def, 0, 1) == FALSE)
		return (FALSE);
	sub_ptr = st->ans_sub.head->next;
	while (sub_ptr != st->ans_sub.tail)
	{
		if (check_optimizeable(st, sub_ptr) == FALSE)
		{
			if (ft_dlstadd_back(&st->ans_def, sub_ptr->num, 1))
				return (FALSE);
			sub_ptr = sub_ptr->next;
		}
	}
	if (ft_dlstadd_back(&st->ans_def, sub_ptr->num, 1))
		return (FALSE);
	return (TRUE);
}

void
	print_ans(t_stacks *st)
{
	t_dlist	*ptr;
	ptr = st->ans_def.head->next;
	while (ptr != st->ans_def.tail)
	{
		
	}
}

int
	opt_print_ans(t_stacks *st)
{
	if (optimize_ans(st) == FALSE)
		return (FALSE);
	//print_ans(st);
	return (TRUE);
}
