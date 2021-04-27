/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:19:38 by ysakuma           #+#    #+#             */
/*   Updated: 2021/04/01 13:43:15 by ysakuma          ###   ########.fr       */
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
}				t_stacks;

int
	check_av(int ac, char **av);
int
	check_stack_a(t_stacks *st);
int
	check_stack(t_stacks *st);
int
	check_duplicate(t_stacks *st);
void
	display_array(int *x, int len);//debug
void
	display_stack(t_stacks *st, char *str);//debug
int
	ft_dlstadd_back(t_stack *stack, int num, int exist);
void
	ft_dlstnew(t_stack *stack, int num, int exist);
int
	print_error(void);
int
	exit_error(void);
int
	check_order(char *buf);
void
	do_order(t_stacks *st, char *buf);
int
	get_do_ord(t_stacks *st);
void
	pack_array(t_stacks *st);
int
	pack_sort_array(t_stacks *st);
int
	build_stack_b(t_stacks *st);
int
	check_over_int_range(char *str);
int
	pack_stack(t_stacks *st, char **av);
int
	push_available(t_stacks *st, char to);
void
	switch_exist(t_dlist *lst);
void
	push_lst(t_stack *from, t_stack *to);
void
	after_push(t_stack *stack);
void
	push(t_stacks *st, char to);
void
	rotate(t_stack *stack);
void
	w_rotate(t_stacks *st);
void
	rev_rotate(t_stack *stack);
void
	w_rev_rotate(t_stacks *st);
void
	swap_num(int *nums, int l, int r);
int
	swap_array(int *nums, int pivot, int *l, int *r);
void
	q_sort_array(int *nums, int left, int right);
void
	sort_array(int *nums, int len);
int
	check_swap_available(t_stack *stack);
void
	swap(t_stack *stack);
void
	w_swap(t_stacks *st);

#endif
