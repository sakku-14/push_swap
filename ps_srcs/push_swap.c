#include "../includes/push_swap.h"

int
	print_error(void)
{
	write(1, "Error\n", 6);
	return (FALSE);
}

int
	exit_error(void)
{
	write(1, "Error\n", 6);
	exit (-1);
}

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
	pack_stack(t_stacks *st, char **av)
{
	int	num;
	int	i;

	num = ft_atoi(av[1]);
	ft_dlstnew(&st->a, num, 1);
	i = 2;
	while (i < st->len + 1)
	{
		num = ft_atoi(av[i]);
		if (ft_dlstadd_back(&st->a, num, 1) == FALSE)
			return (FALSE);
		i++;
	}
	if (build_stack_b(st) == FALSE)
		return (FALSE);
	return (TRUE);
}

int
	check_av(int ac, char **av)
{
	int i;
	int len;

	i = 1;
	while (i < ac)
	{
		len = 0;
		while (av[i][len])
		{
			if (!(ft_isdigit(av[i][len++])))
				return (print_error());
		}
		i++;
	}
	return (TRUE);
}

void
	display_stack(t_stacks *st, char *str)
{
	t_dlist	*lst;
	int		i;
	char	flag;

	printf("________________Stack_Circumstance____________________\n");
	printf("----------%s----------\n", str);
	printf("\n*****************\n>>>>>Stack_A<<<<<\n*****************\n");
	i = 1;
	lst = st->a.head;
	if (lst == st->a.head && lst == st->a.tail)
		printf("h&t--->");
	else if (lst == st->a.head)
		printf("head-->");
	else
		printf("       ");
	if (lst->exist == 1)
		flag = 'o';
	else
		flag = 'x';
	printf("%3d->%3d | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, flag, lst, lst->prev, lst->next);
	i++;
	lst = lst->next;
	while (lst != st->a.head)
	{
		if (lst == st->a.head && lst == st->a.tail)
			printf("h&t--->");
		else if (lst == st->a.tail)
			printf("tail-->");
		else
			printf("       ");
		if (lst->exist == 1)
			flag = 'o';
		else
			flag = 'x';
		printf("%3d->%3d | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, flag, lst, lst->prev, lst->next);
		i++;
		lst = lst->next;
	}

	printf("\n*****************\n>>>>>Stack_B<<<<<\n*****************\n");
	i = 1;
	lst = st->b.head;
	if (lst == st->b.head && lst == st->b.tail)
		printf("h&t--->");
	else if (lst == st->b.head)
		printf("head-->");
	else
		printf("       ");
	if (lst->exist == 1)
		flag = 'o';
	else
		flag = 'x';
	printf("%3d->%3d | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, flag, lst, lst->prev, lst->next);
	i++;
	lst = lst->next;
	while (lst != st->b.head)
	{
		if (lst == st->b.head && lst == st->b.tail)
			printf("h&t--->");
		else if (lst == st->b.tail)
			printf("tail-->");
		else
			printf("       ");
		if (lst->exist == 1)
			flag = 'o';
		else
			flag = 'x';
		printf("%3d->%3d | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, flag, lst, lst->prev, lst->next);
		i++;
		lst = lst->next;
	}
}

int
	check_swap_available(t_stack *stack)
{
	if (stack->head == stack->tail)
		return (FALSE);
	return (TRUE);
}

void
	swap(t_stack *stack)
{
	t_dlist	*next;
	int		tmp;

	if (check_swap_available(stack) == FALSE)
		return ;
	next = stack->head->next;
	tmp = stack->head->num;
	stack->head->num = next->num;
	next->num = tmp;
}

void
	w_swap(t_stacks *st)
{
	swap(&st->a);
	swap(&st->b);
}

int
	push_available(t_stacks *st, char to)
{
	if (to == 'a')
	{
		if (st->b.head == st->b.tail && st->b.head->exist == 0)
			return (FALSE);
	}
	else
	{
		if (st->a.head == st->a.tail && st->a.head->exist == 0)
			return (FALSE);
	}
	return (TRUE);
}

void
	switch_exist(t_dlist *lst)
{
	if (lst->exist == 0)
		lst->exist = 1;
	else
		lst->exist = 0;
}

void
	push_lst(t_stack *from, t_stack *to)
{
	if (to->head->exist != 0)
		to->head = to->head->prev;
	if (to->head->exist == 0)
		switch_exist(to->head);
	to->head->num = from->head->num;
}

void
	after_push(t_stack *stack)
{
	stack->head->num = -1;
	switch_exist(stack->head);
	if (stack->head != stack->tail)
		stack->head = stack->head->next;
}

void
	push(t_stacks *st, char to)
{
	if (push_available(st, to) == FALSE)
		return ;
	if (to == 'a')
	{
		push_lst(&st->b, &st->a);
		after_push(&st->b);
	}
	else
	{
		push_lst(&st->a, &st->b);
		after_push(&st->a);
	}
}

void
	rotate(t_stack *stack)
{
	int tmp;
	t_dlist *ptr;

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
	int tmp;
	t_dlist *ptr;

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

int
	check_stack_a(t_stacks *st)
{
	int		num;
	t_dlist	*ptr;

	if (st->len == 1)
		return (TRUE);
	num = st->a.head->num;
	ptr = st->a.head->next;
	while (ptr != st->a.head)
	{
		if (num > ptr->num)
			return (FALSE);
		num = ptr->num;
		ptr = ptr->next;
	}
	return (TRUE);
}

int
	check_stack(t_stacks *st)
{
	if (st->b.head->exist == 1)
		return (FALSE);
	if (check_stack_a(st) == FALSE)
		return (FALSE);
	return (TRUE);
}

void
	pack_array(t_stacks *st)
{
	int		i;
	t_dlist	*ptr;

	i = 0;
	ptr = st->a.head;
	while (ptr != st->a.tail)
	{
		st->nums[i++] = ptr->num;
		ptr = ptr->next;
	}
	st->nums[i] = ptr->num;
}

//FOR debug
void
	display_array(int *x, int len)
{
	int i = 0;
	while (i < len)
		printf("%d-", x[i++]);
	printf("\n");
}

void
	swap_num(int *nums, int l, int r)
{
	int tmp;

	tmp = nums[l];
	nums[l] = nums[r];
	nums[r] = tmp;
}

int
	swap_array(int *nums, int pivot, int *l, int *r)
{
	while (nums[*l] < pivot)
		(*l)++;
	while (nums[*r] > pivot)
		(*r)--;
	if (*l >= *r)
		return (FALSE);
	swap_num(nums, *l, *r);
	return (TRUE);
}

void
	q_sort_array(int *nums, int left, int right)
{
	int pivot;
	int l;
	int r;

	l = left;
	r = right;
	pivot = nums[l];
	while (1)
	{
		if (swap_array(nums, pivot, &l, &r) == FALSE)
			break ;
		l++;
		r--;
	}
	if (left < l - 1)
		q_sort_array(nums, left, l - 1);
	if (right > r + 1)
		q_sort_array(nums, r + 1, right);
}

void
	sort_array(int *nums, int len)
{
	display_array(nums, len);
	q_sort_array(nums, 0, len - 1);
	display_array(nums, len);
}

int
	pack_sort_array(t_stacks *st)
{
	if (!(st->nums = malloc(sizeof(int) * (st->len))))
		return (FALSE);
	pack_array(st);
	sort_array(st->nums, st->len);
	return (TRUE);
}

void
	attach_tail(t_stacks *st)
{
	push(st, 'a');
	rotate(&st->a);
}

//for check act
void
	check_act(t_stacks *st)
{
	attach_tail(st);
	attach_tail(st);
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
	if (pack_sort_array(&st) == FALSE)
		exit_error();
	//TODO:クイックソート実装
	//TODO:クイックソートで使うスタック動作関数実装し、動作確認
	check_act(&st);
	display_stack(&st, "result");
	exit (0);
}
