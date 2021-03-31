#include "../includes/checker.h"
/*
t_dlist
	*ft_dlstlast(t_checker *checker, t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != checker->head)
		lst = lst->next;
	return (lst);
}
*/
int
	ft_dlstadd_back(t_checker *checker, int num)
{
	t_dlist *new;

	if (!(new = malloc(sizeof(t_dlist))))
		return (FALSE);
	checker->tail->next = new;
	checker->head->prev = new;
	new->num = num;
	new->next = checker->head;
	new->prev = checker->tail;
	checker->tail = new;
	return (TRUE);
}

void
	ft_dlstnew(t_checker *checker, int num)
{
	t_dlist *lst;

	lst = malloc(sizeof(t_dlist));
	lst->num = num;
	lst->next = lst;
	lst->prev = lst;
	checker->head = lst;
	checker->tail = lst;
}

int
	pack_stack(t_checker *checker, char **av)
{
	int	num;
	int	i;

	num = ft_atoi(av[1]);
	ft_dlstnew(checker, num);
	i = 2;
	while (i < checker->len)
	{
		num = ft_atoi(av[i]);
		if (ft_dlstadd_back(checker, num) == FALSE)
			return (FALSE);
		i++;
	}
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
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void
	display_stack(t_checker *checker)
{
	t_dlist	*lst;
	int		i;

	i = 1;
	lst = checker->head;
	printf("%d->%d:addr->%p:prev->%p:next->%p\n", i, lst->num, lst, lst->prev, lst->next);
	i++;
	lst = lst->next;
	while (lst->next != checker->head)
	{
		printf("%d->%d:addr->%p:prev->%p:next->%p\n", i, lst->num, lst, lst->prev, lst->next);
		i++;
		lst = lst->next;
	}
	printf("%d->%d:addr->%p:prev->%p:next->%p\n", i, lst->num, lst, lst->prev, lst->next);
}

int
	main(int ac, char **av)
{
	t_checker	checker;

	if ((checker.len = ac) <= 1 || check_av(ac, av) == FALSE)
		return (FALSE);
	if (pack_stack(&checker, av) == FALSE)
		return (FALSE);
	display_stack(&checker);//for debug
	return (0);
}
