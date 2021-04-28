/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:02:50 by ysakuma           #+#    #+#             */
/*   Updated: 2021/04/28 15:18:10 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret_l;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	ret_l = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&ret_l, del);
			return (NULL);
		}
		ft_lstadd_back(&ret_l, new);
		lst = lst->next;
	}
	return (ret_l);
}
