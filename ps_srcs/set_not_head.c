#include "../includes/push_swap.h"

void
	set_not_head(t_stacks *st)
{
	int		i;
	t_dlist	*ptr;
	t_dlist	*tmp;

	search_bad_head_in_snh(st, &ptr, &tmp);
	i = 0;
	tmp = st->a.head;
	ra_rra_count_in_snh(st, ptr, tmp, &i);
	ra_rra_in_snh(st, i);
}
