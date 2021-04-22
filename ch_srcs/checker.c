#include "../includes/checker.h"

int
	ft_dlstadd_back(t_stack *stack, int num, int exist)
{
	t_dlist *new;

	if (!(new = malloc(sizeof(t_dlist))))
		return (FALSE);
	stack->tail->next = new;
	stack->head->prev = new;
	new->num = num;
	new->exist = exist;
	new->next = stack->head;
	new->prev = stack->tail;
	stack->tail = new;
	return (TRUE);
}

void
	ft_dlstnew(t_stack *stack, int num, int exist)
{
	t_dlist *lst;

	lst = malloc(sizeof(t_dlist));
	lst->num = num;
	lst->exist = exist;
	lst->next = lst;
	lst->prev = lst;
	stack->head = lst;
	stack->tail = lst;
}

int
	build_stack_b(t_stacks *st)
{
	int	i;

	ft_dlstnew(&st->b, -1, 0);
	i = 2;
	while (i < st->len + 1)
	{
		if (ft_dlstadd_back(&st->b, -1, 0) == FALSE)
			return (FALSE);
		i++;
	}
	st->b.tail = st->b.head;
	return (TRUE);
}





int
	check_order(char *buf)
{
	if (ft_strlen(buf) == 2)
	{
		if (ft_strnstr(buf, "sa", 2) || ft_strnstr(buf, "sb", 2))
			return (TRUE);
		else if (ft_strnstr(buf, "ss", 2))
			return (TRUE);
		else if (ft_strnstr(buf, "pa", 2) || ft_strnstr(buf, "pb", 2))
			return (TRUE);
		else if (ft_strnstr(buf, "ra", 2) || ft_strnstr(buf, "rb", 2))
			return (TRUE);
		else if (ft_strnstr(buf, "rr", 2))
			return (TRUE);
	}
	else if (ft_strlen(buf) == 3)
	{
		if (ft_strnstr(buf, "rra", 3) || ft_strnstr(buf, "rrb", 3))
			return (TRUE);
		else if (ft_strnstr(buf, "rrr", 3))
			return (TRUE);
	}
	return (FALSE);
}

void
	do_order(t_stacks *st, char *buf)
{
	if (ft_strnstr(buf, "sa", 2))
		swap(&st->a);
	else if (ft_strnstr(buf, "sb", 2))
		swap(&st->b);
	else if (ft_strnstr(buf, "ss", 2))
		w_swap(st);
	else if (ft_strnstr(buf, "pa", 2))
		push(st, 'a');
	else if (ft_strnstr(buf, "pb", 2))
		push(st, 'b');
	else if (ft_strnstr(buf, "rra", 3))
		rev_rotate(&st->a);
	else if (ft_strnstr(buf, "rrb", 3))
		rev_rotate(&st->b);
	else if (ft_strnstr(buf, "rrr", 3))
		w_rev_rotate(st);
	else if (ft_strnstr(buf, "ra", 2))
		rotate(&st->a);
	else if (ft_strnstr(buf, "rb", 2))
		rotate(&st->b);
	else if (ft_strnstr(buf, "rr", 2))
		w_rotate(st);
}

int
	get_do_ord(t_stacks *st)
{
	int ret;
	char *buf;

	while ((ret = get_next_line(0, &buf)) != 0)
	{
		if (ret < 0)
			return (FALSE);
		if (check_order(buf) == FALSE)
			return (FALSE);
		do_order(st, buf);
	}
	return (TRUE);
}

int
	main(int ac, char **av)
{
	t_stacks	st;

	if (ac == 1 || check_av(ac, av) == FALSE)
		exit_error();
	st.len = ac - 1;
	if (pack_stack(&st, av) == FALSE)
		exit_error();
	//TODO: error act for duplicate
	if (pack_sort_array(&st) == FALSE || check_duplicate(&st) == FALSE)
		exit_error();
	if (get_do_ord(&st) == FALSE)
		exit_error();
	//display_stack(&st, "result");
	if (check_stack(&st) == TRUE)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit (0);
}
