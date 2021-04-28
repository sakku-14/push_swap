#include "../includes/push_swap.h"

int
	pack_sort_array(t_stacks *st)
{
	st->nums = malloc(sizeof(int) * (st->len));
	if (st->nums == NULL)
		return (FALSE);
	pack_array(st);
	sort_array(st->nums, st->len);
	st->n_ptr = 0;
	return (TRUE);
}
