/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:19:38 by ysakuma           #+#    #+#             */
/*   Updated: 2021/04/10 13:30:20 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHECKER_H
# define _CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

# define FALSE -1
# define TRUE 0

typedef struct	s_dlist
{
	int				num;
	int				group;
	int				exist;// exist->1, not->0
	struct s_dlist	*prev;
	struct s_dlist	*next;
}				t_dlist;

typedef struct	s_stack
{
	t_dlist	*head;
	t_dlist	*tail;
}				t_stack;

typedef struct	s_stacks
{
	t_stack	a;
	t_stack	b;
	int		*nums;
	int		n_ptr;
	int		len;
	int		grp_ctr;
}				t_stacks;

int
	asc_pres_next(t_stacks *st, t_dlist *ptr);
int
	max_is(int a, int b);
int
	asc_count(t_stacks *st);
void
	attach_tail(t_stacks *st);
void
	inc_i_for_5(int *i);
int
	check_a_asc(t_stacks *st);
int
	check_av(int ac, char **av);
int
	check_duplicate(t_stacks *st);
int
	check_stack_a(t_stacks *st);
int
	check_stack(t_stacks *st);
void
	display_array(int *x, int len);//debug
void
	display_stack(t_stacks *st, char *str);//debug
int
	print_error(void);
int
	exit_error(void);
void
	final_rotates(t_stacks *st);
void
	next_ptr_in_a(t_stacks *st, t_dlist **ptr);
void
	pack_array(t_stacks *st);
int
	pack_sort_array(t_stacks *st);
int
	ft_dlstadd_back(t_stack *stack, int num, int exist);
int
	ft_dlstnew(t_stack *stack, int num, int exist);
int
	build_stack_b(t_stacks *st);
int
	check_over_int_range(char *str);
int
	pack_stack(t_stacks *st, char **av);
void
	check_f_len(t_stacks *st, int *f_len, t_dlist *ptr, int num);
void
	check_s_len(t_stacks *st, int *s_len, t_dlist *ptr, int num);
void
	push_fs_act(t_stacks *st, int *f_len, int *s_len, int num);
void
	push_first_second(t_stacks *st, int *f_len, int *s_len, int num);
int
	push_available(t_stacks *st, char to);
void
	switch_exist(t_dlist *lst);
void
	push_lst(t_stack *from, t_stack *to);
void
	after_push(t_stack *stack);
int
	push(t_stacks *st, char to);
void
	q_sort_stack_a(t_stacks *st);
int
	set_pivot_b(t_stacks *st, int *counter);
int
	all_under_pivot(t_stack *b, int pivot);
void
	q_sort_stack_b(t_stacks *st);
void
	q_sort_stack_first(t_stacks *st);
void
	q_sort_stack(t_stacks *st);
void
	rotate(t_stack *stack);
void
	w_rotate(t_stacks *st);
void
	rev_rotate(t_stack *stack);
void
	w_rev_rotate(t_stacks *st);
void
	next_index_is(int *i, int len);
int
	scale_len_is_3(t_stacks *st, t_dlist **ptr, int *i);
void
	set_pair_ra(t_stacks *st, int i);
void
	set_pair_rra(t_stacks *st, int i);
void
	set_asc_head(t_stacks *st);
void
	set_not_head(t_stacks *st);
int
	wated_num(t_stacks *st, char *flag);
int
	set_sorted(t_stacks *st);
int
	min_is(int a, int b);
int
	ra_need_sub(t_stacks *st);
void
	set_three_asc(t_stacks *st);
void
	set_three_order(t_stacks *st);
void
	w_push(t_stacks *st, char to);
void
	set_three(t_stacks *st);
void
	set_two(t_stacks *st);
void
	swap_num(int *nums, int l, int r);
int
	swap_array(int *nums, int pivot, int *l, int *r);
void
	q_sort_array(int *nums, int left, int right);
void
	sort_array(int *nums, int len);
void
	push_min_to_a(t_stacks *st);
void
	set_five(t_stacks *st);
void
	sort_five(t_stacks *st);
void
	sort_less_elem(t_stacks *st);
int
	check_three_asc(t_stacks *st);
int
	ra_need(t_stacks *st, int num);
void
	sort_three(t_stacks *st);
int
	check_swap_available(t_stack *stack);
void
	swap(t_stack *stack);
void
	w_swap(t_stacks *st);
void
	search_bad_head_in_snh(t_stacks *st, t_dlist **ptr, t_dlist **tmp);
void
	ra_rra_count_in_snh(t_stacks *st, t_dlist *ptr, t_dlist *tmp, int *i);
void
	ra_rra_in_snh(t_stacks *st, int i);

#endif
