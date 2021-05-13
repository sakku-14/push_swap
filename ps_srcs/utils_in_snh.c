#include "../includes/push_swap.h"

void
	search_bad_head_in_snh(t_stacks *st, t_dlist **ptr, t_dlist **tmp)
{
	int	counter;
	int	i;

	counter = 0;
	*ptr = st->a.head;
	while (counter < 5)
	{
		i = 0;
		while (i < st->len)
		{
			if ((*ptr)->num == st->nums[i])
				break ;
			i++;
		}
		*tmp = *ptr;
		if (scale_len_is_3(st, ptr, &i) == TRUE)
			break ;
		*ptr = *tmp;
		next_ptr_in_a(st, ptr);
		counter++;
	}
}

void
	ra_rra_count_in_snh(t_stacks *st, t_dlist *ptr, t_dlist *tmp, int *i)
{
	while (tmp->num != ptr->num)
	{
		next_ptr_in_a(st, &tmp);
		(*i)++;
	}
}

void
	ra_rra_in_snh(t_stacks *st, int i)
{
	if (i < 3)
	{
		while (i > 0)
		{
			rotate(&st->a);
			if (add_oper(st, 6) == FALSE)
				exit_error();
			i--;
		}
	}
	else
	{
		while (i < 5)
		{
			rev_rotate(&st->a);
			if (add_oper(st, 9) == FALSE)
				exit_error();
			i++;
		}
	}
}
