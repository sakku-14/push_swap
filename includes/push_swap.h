/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:19:38 by ysakuma           #+#    #+#             */
/*   Updated: 2021/04/06 17:29:42 by ysakuma          ###   ########.fr       */
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

#endif
