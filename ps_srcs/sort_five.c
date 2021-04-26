#include "../includes/push_swap.h"

void
	push_min_to_a(t_stacks *st)
{
	int	f_len;
	int	s_len;

	push_first_second(st, &f_len, &s_len, 0);
	push_first_second(st, &f_len, &s_len, 1);
}

void
	set_five(t_stacks *st)
{
	push_min_to_a(st);
	set_three_asc(st);
	w_push(st, 'a');
}

void
	sort_five(t_stacks *st)
{
	int	counter;

	counter = asc_count(st);
	if (counter == 1)
		set_five(st);
	else if (counter == 2)
		set_three(st);
	else if (counter == 3)
		set_two(st);
	if (check_stack(st) == FALSE)
		final_rotates(st);
}