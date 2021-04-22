#include "../includes/common_utility.h"

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

int
	check_duplicate(t_stacks *st)
{
	int i;

	i = 0;
	while (i < st->len - 1)
	{
		if (st->nums[i] == st->nums[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}