#include "../includes/checker.h"

int
	pack_sort_array(t_stacks *st)
{
	if (!(st->nums = malloc(sizeof(int) * (st->len))))
		return (FALSE);
	pack_array(st);
	sort_array(st->nums, st->len);
	st->n_ptr = 0;
	return (TRUE);
}