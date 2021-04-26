#include "../includes/push_swap.h"

void
	rotate(t_stack *stack)
{
	int t_num;
	int t_group;
	t_dlist *ptr;

	t_num = stack->head->num;
	t_group = stack->head->group;
	ptr = stack->head;
	while (ptr != stack->tail)
	{
		ptr->num = ptr->next->num;
		ptr->group = ptr->next->group;
		ptr = ptr->next;
	}
	ptr->num = t_num;
	ptr->group = t_group;
}

void
	w_rotate(t_stacks *st)
{
	rotate(&st->a);
	rotate(&st->b);
}

void
	rev_rotate(t_stack *stack)
{
	int t_num;
	int t_group;
	t_dlist *ptr;

	t_num = stack->tail->num;
	t_group = stack->tail->group;
	ptr = stack->tail;
	while (ptr != stack->head)
	{
		ptr->num = ptr->prev->num;
		ptr->group = ptr->prev->group;
		ptr = ptr->prev;
	}
	ptr->num = t_num;
	ptr->group = t_group;
}

void
	w_rev_rotate(t_stacks *st)
{
	rev_rotate(&st->a);
	rev_rotate(&st->b);
}