/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:19:38 by ysakuma           #+#    #+#             */
/*   Updated: 2021/03/28 19:06:29 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHECKER_H
# define _CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct	s_stack
{
	int	num;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_checker
{
	t_stack	*top;
	t_stack	*end;
	t_stack	*head;
	t_stack	*tail;
	int		len;
}				t_checker;

#endif
