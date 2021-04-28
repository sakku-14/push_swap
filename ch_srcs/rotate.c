#include "../includes/checker.h"

void
	rotate(t_stack *stack)
{
	int		tmp;
	t_dlist	*ptr;

	tmp = stack->head->num;
	ptr = stack->head;
	while (ptr != stack->tail)
	{
		ptr->num = ptr->next->num;
		ptr = ptr->next;
	}
	ptr->num = tmp;
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
	int		tmp;
	t_dlist	*ptr;

	tmp = stack->tail->num;
	ptr = stack->tail;
	while (ptr != stack->head)
	{
		ptr->num = ptr->prev->num;
		ptr = ptr->prev;
	}
	ptr->num = tmp;
}

void
	w_rev_rotate(t_stacks *st)
{
	rev_rotate(&st->a);
	rev_rotate(&st->b);
}
