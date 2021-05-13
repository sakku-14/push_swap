#include "../includes/push_swap.h"

int
	add_oper(t_stacks *st, int oper)
{
	if (ft_dlstadd_back(&st->ans_sub, oper, 1) == FALSE)
		return (FALSE);
	return (TRUE);
}
