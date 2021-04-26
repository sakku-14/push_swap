#include "../includes/push_swap.h"

void
	inc_i_for_5(int *i)
{
	if (*i != 4)
		(*i)++;
	else
		*i = 0;
}

int
	check_a_asc(t_stacks *st)
{
	int	i;
	int	counter;
	t_dlist	*ptr;

	i = 0;
	counter = 0;
	ptr = st->a.head;
	while (st->nums[i] != ptr->num)
		i++;
	while (counter != 3)
	{
		if (st->nums[i] == st->b.head->num || st->nums[i] == st->b.tail->num)
			inc_i_for_5(&i);
		else
		{
			if (st->nums[i] != ptr->num)
				return (FALSE);
			counter++;
			inc_i_for_5(&i);
			if (ptr == st->a.tail)
				ptr = st->a.head;
			else
				ptr = ptr->next;
		}
	}
	return (TRUE);
}