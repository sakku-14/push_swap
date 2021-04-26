#include "../includes/push_swap.h"

void
	pack_array(t_stacks *st)
{
	int		i;
	t_dlist	*ptr;

	i = 0;
	ptr = st->a.head;
	while (ptr != st->a.tail)
	{
		st->nums[i++] = ptr->num;
		ptr = ptr->next;
	}
	st->nums[i] = ptr->num;
}