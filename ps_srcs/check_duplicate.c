#include "../includes/push_swap.h"

int
	check_duplicate(t_stacks *st)
{
	int	i;

	i = 0;
	while (i < st->len - 1)
	{
		if (st->nums[i] == st->nums[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
