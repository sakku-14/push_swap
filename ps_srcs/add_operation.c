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
/*
int
	check_optimizeable(t_dlist *sub_ptr, t_dlist *def_ptr)
{
	if (sub_ptr->num == 4 && sub_ptr->next->num == 5)
		sub_ptr = sub_ptr->next->next;
	else if (sub_ptr->num == 5 && sub_ptr->next->num == 4)
		sub_ptr = sub_ptr->next->next;
	else if (sub_ptr->num == 6 && sub_ptr->next->num == 9)
		sub_ptr = sub_ptr->next->next;
	else if (sub_ptr->num == 9 && sub_ptr->next->num == 6)
		sub_ptr = sub_ptr->next->next;
	else if (sub_ptr->num == 7 && sub_ptr->next->num == 10)
		sub_ptr = sub_ptr->next->next;
	else if (sub_ptr->num == 10 && sub_ptr->next->num == 7)
		sub_ptr = sub_ptr->next->next;
	else if (sub_ptr->num == 8 && sub_ptr->next->num == 11)
		sub_ptr = sub_ptr->next->next;
	else if (sub_ptr->num == 11 && sub_ptr->next->num == 8)
		sub_ptr = sub_ptr->next->next;
	else if (sub_ptr->num == 6 && sub_ptr->next->num == 7)
		def_ptr;
	else if (sub_ptr->num == 5 && sub_ptr->next->num == 4)
		sub_ptr = sub_ptr->next->next;
}

int
	optimize_ans(t_stacks *st)
{
	t_dlist	*sub_ptr;
	t_dlist	*def_ptr;

	if (ft_dlstnew(&st->def_sub, 0, 1) == FALSE)
		return (FALSE);
	sub_ptr = st->ans_sub.head->next;
	while (sub_ptr != st->ans_sub.tail)
	{
		if (check_optimizeable(sub_ptr, def_ptr) == FALSE)
		{
			if (ft_dlstadd_back(&st->ans_def, sub_ptr->num, 1))
				return (FALSE);
			sub_ptr = sub_ptr->next;
			def_ptr = def_ptr->next;
		}
	}
	return (TRUE);
}

void
	print_ans(t_stacks *st)
{
}

int
	opt_print_ans(t_stacks *st)
{
	if (optimize_ans(st) == FALSE)
		return (FALSE);
	print_ans(st);
	return (TRUE);
}
*/
