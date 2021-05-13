#include "../includes/push_swap.h"

int
	init_st_ans(t_stacks *st)
{
	if (ft_dlstnew(&st->ans_sub, 0, 1) == FALSE)
		return (FALSE);
	return (TRUE);
}
