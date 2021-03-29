#include "../includes/checker.h"

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist *tmp;

	tmp = *lst;
	if (!new)
		return ;
	if (*lst)
	{
		tmp = ft_dlstlast(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
}

t_dlist
	*ft_dlstnew(int num)
{
	t_dlist *lst;

	if (!(lst = malloc(sizeof(t_dlist))))
		return (NULL);
	lst->next = lst;
	lst->prev = lst;
	lst->num = num;
	return (lst);
}

void
	pack_stack(t_checker *checker, char **av)
{
	//TODO: pack av to stack
	int	first_num;

	first_num = ft_atoi(av[1]);
	checker->top = ft_dlstnew(first_num);
}

int
	main(int ac, char **av)
{
	t_checker	checker;

	pack_stack(&checker, av);
	printf("ac:%d,num:%d\n", ac, checker.top->num);
	return (0);
}
