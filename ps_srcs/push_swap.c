/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:09:05 by ysakuma           #+#    #+#             */
/*   Updated: 2021/05/04 12:58:30 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

__attribute__((destructor))
void    end()
{
    system("leaks push_swap");
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
