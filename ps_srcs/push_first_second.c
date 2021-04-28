#include "../includes/push_swap.h"

void
	check_f_len(t_stacks *st, int *f_len, t_dlist *ptr, int num)
{
	while (st->nums[num] != ptr->num)
	{
		(*f_len)++;
		ptr = ptr->next;
	}
}

void
	check_s_len(t_stacks *st, int *s_len, t_dlist *ptr, int num)
{
	while (st->nums[num] != ptr->num)
	{
		(*s_len)++;
		ptr = ptr->prev;
	}
}

void
	push_fs_act(t_stacks *st, int *f_len, int *s_len, int num)
{
	if (*f_len < *s_len)
	{
		while (st->a.head->num != st->nums[num])
		{
			rotate(&st->a);
			write(1, "ra\n", 3);
		}
		push(st, 'b');
		write(1, "pb\n", 3);
	}
	else
	{
		while (st->a.head->num != st->nums[num])
		{
			rev_rotate(&st->a);
			write(1, "rra\n", 4);
		}
		push(st, 'b');
		write(1, "pb\n", 3);
	}
}

void
	push_first_second(t_stacks *st, int *f_len, int *s_len, int num)
{
	t_dlist	*ptr;

	*f_len = 0;
	*s_len = 1;
	ptr = st->a.head;
	check_f_len(st, f_len, ptr, num);
	ptr = st->a.tail;
	check_s_len(st, s_len, ptr, num);
	push_fs_act(st, f_len, s_len, num);
}
