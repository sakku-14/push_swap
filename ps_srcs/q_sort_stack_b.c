#include "../includes/push_swap.h"

int
	set_pivot_b(t_stacks *st, int *counter)
{
	int		len;
	int		*nums;
	t_dlist	*ptr;

	len = 0;
	nums = malloc(sizeof(int) * st->len);
	ptr = st->b.head;
	while (ptr != st->b.tail)
	{
		nums[len] = ptr->num;
		ptr = ptr->next;
		len++;
	}
	nums[len] = ptr->num;
	len++;
	*counter = len;
	q_sort_array(nums, 0, len - 1);
	return (nums[(len - 1) / 2]);
}

int
	all_under_pivot(t_stack *b, int pivot)
{
	t_dlist	*ptr;

	ptr = b->head;
	while (ptr != b->tail)
	{
		if (ptr->num > pivot)
			return (FALSE);
		ptr = ptr->next;
	}
	if (ptr->num > pivot)
		return (FALSE);
	return (TRUE);
}

static int
	q_sort_stack_b_sub(t_stacks *st, int pivot)
{
	if (st->b.head->num > pivot)
	{
		if (push(st, 'a') == FALSE)
			return (FALSE);
		st->a.head->group = st->grp_ctr;
		write(1, "pa\n", 3);
	}
	else
	{
		rotate(&(st->b));
		write(1, "rb\n", 3);
	}
	return (TRUE);
}

void
	q_sort_stack_b(t_stacks *st)
{
	int	pivot;
	int	counter;

	pivot = set_pivot_b(st, &counter);
	st->grp_ctr++;
	while (counter > 0)
	{
		if (check_stack(st) == TRUE)
			break ;
		counter -= set_sorted(st);
		if (check_stack(st) == TRUE)
			break ;
		if (q_sort_stack_b_sub(st, pivot) == FALSE)
			break ;
		counter--;
		if (check_stack(st) == TRUE)
			break ;
		counter -= set_sorted(st);
		if (check_stack(st) == TRUE)
			break ;
	}
}
