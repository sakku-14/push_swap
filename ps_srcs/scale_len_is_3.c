#include "../includes/push_swap.h"

void
	next_index_is(int *i, int len)
{
	if (*i == len - 1)
		*i = 0;
	else
		(*i)++;
}

int
	scale_len_is_3(t_stacks *st, t_dlist **ptr, int *i)
{
	int len;

	len = 0;
	while ((*ptr)->num == st->nums[*i])
	{
		len++;
		next_index_is(i, st->len);
		next_ptr_in_a(st, ptr);
	}
	if (len == 3)
		return (TRUE);
	return (FALSE);
}