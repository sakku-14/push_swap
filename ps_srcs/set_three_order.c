#include "../includes/push_swap.h"

void
	set_three_order(t_stacks *st)
{
	int	i;

	i = 0;
	while (st->b.head->num != st->nums[i])
		i++;
	if (i != 4)
		i++;
	else
		i = 0;
	while (st->a.head->num != st->nums[i])
	{
		rotate(&st->a);
		write(1, "ra\n", 3);
	}
}
