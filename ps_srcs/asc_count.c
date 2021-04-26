#include "../includes/push_swap.h"

int
	asc_pres_next(t_stacks *st, t_dlist *ptr)
{
	int	i;

	i = 0;
	while (st->nums[i] != ptr->num)
		i++;
	if (i == st->len - 1)
		i = 0;
	else
		i++;
	if (ptr == st->a.tail)
		ptr = st->a.head;
	else
		ptr = ptr->next;
	if (st->nums[i] == ptr->num)
		return (TRUE);
	return (FALSE);
}

int
	max_is(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int
	asc_count(t_stacks *st)
{
	int	ret;
	int	counter;
	t_dlist	*ptr;
	t_dlist	*tmp;

	counter = 0;
	tmp = st->a.head;
	while (counter == 0 || tmp != st->a.head)
	{
		counter = 1;
		ptr = tmp;
		while (asc_pres_next(st, ptr) == TRUE && counter != 5)
		{
			counter++;
			ptr->group = 1;
			if (ptr != st->a.tail)
				ptr->next->group = 1;
			else
				st->a.head->group = 1;
			ptr = ptr->next;
		}
		ret = max_is(counter, ret);
		tmp = tmp->next;
	}
	return (ret);
}