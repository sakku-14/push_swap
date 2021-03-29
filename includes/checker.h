/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:19:38 by ysakuma           #+#    #+#             */
/*   Updated: 2021/03/29 12:45:29 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHECKER_H
# define _CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"

typedef struct	s_dlist
{
	int				num;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}				t_dlist;

typedef struct	s_checker
{
	t_dlist	*top;
	t_dlist	*end;
	t_dlist	*head;
	t_dlist	*tail;
	int		len;
}				t_checker;

#endif
