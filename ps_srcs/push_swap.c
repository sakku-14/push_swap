/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:09:05 by ysakuma           #+#    #+#             */
/*   Updated: 2021/04/20 19:43:29 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	new->group = 0;
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
	lst->group = 0;
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
			if (av[i][len] == '-' || av[i][len] == '+')
				len++;
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

	printf("\n________________Stack_Circumstance____________________\n");
	printf("----------%s----------\n", str);
	printf("*****************\n>>>>>Stack_A<<<<<\n*****************\n");
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
	printf("%3d->%3d(%d) | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, lst->group, flag, lst, lst->prev, lst->next);
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
		printf("%3d->%3d(%d) | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, lst->group, flag, lst, lst->prev, lst->next);
		i++;
		lst = lst->next;
	}

	printf("*****************\n>>>>>Stack_B<<<<<\n*****************\n");
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
	printf("%3d->%3d(%d) | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, lst->group, flag, lst, lst->prev, lst->next);
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
		printf("%3d->%3d(%d) | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, lst->group, flag, lst, lst->prev, lst->next);
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

int
	push(t_stacks *st, char to)
{
	if (push_available(st, to) == FALSE)
		return (FALSE);
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
	return (TRUE);
}

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
		if (ptr == st->a.tail)
			return (TRUE);
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
	q_sort_array(nums, 0, len - 1);
	//display_array(nums, len);
}

int
	pack_sort_array(t_stacks *st)
{
	if (!(st->nums = malloc(sizeof(int) * (st->len))))
		return (FALSE);
	pack_array(st);
	sort_array(st->nums, st->len);
	st->n_ptr = 0;
	return (TRUE);
}

void
	attach_tail(t_stacks *st)
{
	push(st, 'a');
	rotate(&st->a);
	st->a.tail->group = -1;
}

int
	wated_num(t_stacks *st, char *flag)
{
//	printf("st->n_ptr:%d, st->nums[st->n_ptr]:%d, st->a.head->num:%d, st->b.head->num:%d\n", st->n_ptr,st->nums[st->n_ptr], st->a.head->num, st->b.head->num);
	if (st->n_ptr >= st->len)
		return (FALSE);
	if (st->nums[st->n_ptr] == st->a.head->num)
	{
		*flag = 'a';
		return (TRUE);
	}
	else if (st->nums[st->n_ptr] == st->b.head->num)
	{
		*flag = 'b';
		return (TRUE);
	}
	return (FALSE);
}

int
	set_sorted(t_stacks *st)
{
	char	flag;
	int		counter;

	counter = 0;
	while (wated_num(st, &flag) == TRUE && st->n_ptr < st->len)
	{
		if (flag == 'a')
		{
			rotate(&(st->a));
			st->a.tail->group = -1;
			write(1, "ra\n", 3);
		}
		else
		{
			attach_tail(st);
			write(1, "pa\nra\n", 6);
			counter++;
		}
		flag = '\0';
		st->n_ptr++;
	}
	return (counter);
}

void
	q_sort_stack_first(t_stacks *st)
{
	int		pivot;
	int		counter;

	pivot = st->nums[(st->len - 1) / 2];
	counter = 0;
	while (counter < st->len)
	{
		if (st->a.head->num <= pivot)
		{
			push(st, 'b');
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(&(st->a));
			write(1, "ra\n", 3);
		}
		counter++;
	}
}

int
	set_pivot_b(t_stacks *st, int *counter)
{
	int		len;
	int		nums[st->len];
	t_dlist	*ptr;

	len = 0;
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
	t_dlist *ptr;

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

void
	q_sort_stack_b(t_stacks *st)
{
	int		pivot;
	int		counter;

	pivot = set_pivot_b(st, &counter);
	st->grp_ctr++;
	while (counter > 0)
	{
		if (check_stack(st) == TRUE)
			break;
		counter -= set_sorted(st);
		if (check_stack(st) == TRUE)
			break;
		if (st->b.head->num > pivot)
		{
			if (push(st, 'a') == FALSE)
				break;
			st->a.head->group = st->grp_ctr;
			write(1, "pa\n", 3);
		}
		else
		{
			//display_stack(st, "check act");
			rotate(&(st->b));
			write(1, "rb\n", 3);
		}
		counter--;
		//display_stack(st, "after act in sort b");
		if (check_stack(st) == TRUE)
			break;
		counter -= set_sorted(st);
		if (check_stack(st) == TRUE)
			break;
	}
}

void
	q_sort_stack_a(t_stacks *st)
{
	int group;

	group = st->a.head->group;
	while (st->a.head->group == group && st->a.head->num != st->nums[0])
	{
	//display_stack(st, "before push to b in sort a");
		push(st, 'b');
		write(1, "pb\n", 3);
		set_sorted(st);
	//display_stack(st, "after push to b in sort a");
	}
}

void
	q_sort_stack(t_stacks *st)
{
	st->grp_ctr = 0;
	//ピボット以下の数をスタックBへ送る
	q_sort_stack_first(st);// first act for q_sort
	//display_stack(st, "after sort first");
	//半々の状態でソート済の数がA,Bの先頭にあればAの末尾に送っていく
	set_sorted(st);
	//display_stack(st, "after sort first and set_sorted");
	//ソート済で無ければ以下のwhileでソート完了までループし続ける
	while (check_stack(st) == FALSE)
	{
		//TODO: ソート終了してない時の処理
		//Bが空っぽの時のソート
		if (st->b.head->exist == 0)
		{
			//TODO: s_bが空の時
	//display_stack(st, "before sort a");
			//Aから前回のq_sort_stack_bでAに同タイミングでプッシュした数（同グループ番号）をBへ送る
			q_sort_stack_a(st);
	//display_stack(st, "after sort a");
		}
		//Bに何かしら要素が入ってる時
		else
		{
			//TODO: s_bに残ってる時
	//display_stack(st, "before sort b");
			//ピボットより大きい数をスタックAへ送る
			q_sort_stack_b(st);
	//display_stack(st, "after sort b");
		}
		//display_stack(st, "after each sort");
	}
	//display_stack(st, "after sort");
}

int
	check_three_asc(t_stacks *st)
{
	int	i;
	int	counter;
	t_dlist	*ptr;

	i = 0;
	while (st->nums[i] != st->a.head->num)
		i++;
	counter = 0;
	ptr = st->a.head;
	while (counter != 3)
	{
		if (i == st->len)
			i = 0;
		if (ptr->num == st->nums[i])
			counter++;
		else
			return (FALSE);
		if (ptr != st->a.tail)
			ptr = ptr->next;
		i++;
	}
	return (TRUE);
}

int
	ra_need(t_stacks *st, int num)
{
	int	head;
	t_dlist	*ptr;

	head = 0;
	ptr = st->a.head;
	while (st->nums[0] != ptr->num)
	{
		ptr = ptr->next;
		head++;
	}
	if (head <= num / 2)
		return (TRUE);
	return (FALSE);
}

void
	sort_three(t_stacks *st)
{
	if (check_three_asc(st) == FALSE)
	{
		swap(&st->a);
		write(1, "sa\n", 3);
	}
	if (check_stack_a(st) == FALSE)
	{
		if (ra_need(st, 3) == TRUE)
		{
			rotate(&st->a);
			write(1, "ra\n", 3);
		}
		else
		{
			rev_rotate(&st->a);
			write(1, "rra\n", 4);
		}
	}
}

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

void
	final_rotates(t_stacks *st)
{
	while (check_stack_a(st) == FALSE)
	{
		if (ra_need(st, 5) == TRUE)
		{
			rotate(&st->a);
			write(1, "ra\n", 3);
		}
		else
		{
			rev_rotate(&st->a);
			write(1, "rra\n", 4);
		}
	}
}

void
	set_pair_ra(t_stacks *st, int i)
{
	while (i > 0)
	{
		rotate(&st->a);
		write(1, "ra\n", 3);
		i--;
	}
}

void
	set_pair_rra(t_stacks *st, int i)
{
	while (i < 5)
	{
		rev_rotate(&st->a);
		write(1, "rra\n", 4);
		i++;
	}
}

void
	set_asc_head(t_stacks *st)
{
	int	i;
	t_dlist	*ptr;

	i = 0;
	ptr = st->a.head;
	while (i < 5)
	{
		if (asc_pres_next(st, ptr) == TRUE)
			break;
		i++;
		ptr = ptr->next;
	}
	if (i < 3)
		set_pair_ra(st, i);
	else
		set_pair_rra(st, i);
}

void
	w_push(t_stacks *st, char to)
{
	push(st, to);
	push(st, to);
	if (to == 'b')
		write(1, "pb\npb\n", 6);
	else
		write(1, "pa\npa\n", 6);
}

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

int
	min_is(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int
	ra_need_sub(t_stacks *st)
{
	int	i;
	int	min;
	t_dlist	*ptr;

	ptr = st->a.head;
	min = INT_MAX;
	while (ptr != st->a.tail)
	{
		min = min_is(min, ptr->num);
		ptr = ptr->next;
	}
	min = min_is(min, ptr->num);
	i = 0;
	ptr = st->a.head;
	while (ptr != st->a.tail)
	{
		if (ptr->num == min)
			break;
		i++;
		ptr = ptr->next;
	}
	if (i < 2)
		return (TRUE);
	return (FALSE);
}

void
	set_three_asc(t_stacks *st)
{
	if (check_a_asc(st) == FALSE)
	{
		swap(&st->a);
		write(1, "sa\n", 3);
	}
	if (check_stack_a(st) == FALSE)
	{
		if (ra_need_sub(st) == TRUE)
		{
			rotate(&st->a);
			write(1, "ra\n", 3);
		}
		else
		{
			rev_rotate(&st->a);
			write(1, "rra\n", 4);
		}
	}
}

void
	set_three_order(t_stacks *st)
{
	int	i;

	i = 0;
	while (st->b.head->num != st->nums[i])
		i++;
	if (i != 4)
		i++;
	else
		i = 0;
	while (st->a.head->num != st->nums[i])
	{
		rotate(&st->a);
		write(1, "ra\n", 3);
	}
}

void
	set_three(t_stacks *st)
{
	set_asc_head(st);
	w_push(st, 'b');
	set_three_asc(st);
	set_three_order(st);
	w_push(st, 'a');
}

void
	next_ptr_in_a(t_stacks *st, t_dlist **ptr)
{
	if (*ptr != st->a.tail)
		*ptr = (*ptr)->next;
	else
		*ptr = st->a.head;
}

void
	next_index_is(int *i, int len)
{
	if (*i == len - 1)
		*i = 0;
	else
		(*i)++;
}

int
	scale_len_is_3(t_stacks *st, t_dlist **ptr, int *i)
{
	int len;

	len = 0;
	while ((*ptr)->num == st->nums[*i])
	{
		len++;
		next_index_is(i, st->len);
		next_ptr_in_a(st, ptr);
	}
	if (len == 3)
		return (TRUE);
	return (FALSE);
}

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
				break;
			i++;
		}
		*tmp = *ptr;
		if (scale_len_is_3(st, ptr, &i) == TRUE)
			break;
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
			write(1, "ra\n", 3);
			i--;
		}
	}
	else
	{
		while (i < 5)
		{
			rev_rotate(&st->a);
			write(1, "rra\n", 4);
			i++;
		}
	}
}

void
	set_not_head(t_stacks *st)
{
	int	i;
	t_dlist	*ptr;
	t_dlist	*tmp;

	search_bad_head_in_snh(st, &ptr, &tmp);
	i = 0;
	tmp = st->a.head;
	ra_rra_count_in_snh(st, ptr, tmp, &i);
	ra_rra_in_snh(st, i);
}

void
	set_two(t_stacks *st)
{
	set_not_head(st);
	swap(&st->a);
	write(1, "sa\n", 3);
}

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

void
	sort_less_elem(t_stacks *st)
{
	if (st->len == 3)
		sort_three(st);
	else if (st->len == 5)
		sort_five(st);
}

int
	check_duplicate(t_stacks *st)
{
	int i;

	i = 0;
	while (i < st->len - 1)
	{
		if (st->nums[i] == st->nums[i + 1])
			return (FALSE);
		i++;
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
	if (check_stack(&st) == TRUE)
		exit (0);
	if (pack_sort_array(&st) == FALSE || check_duplicate(&st) == FALSE)
		exit_error();
	if (st.len == 3 || st.len == 5)
		sort_less_elem(&st);
	else
		q_sort_stack(&st);
	exit (0);
}
