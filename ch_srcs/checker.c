#include "../includes/checker.h"

//TODO: improve lstadd_back for dlst

t_dlist
	*ft_dlstlast(t_checker *checker, t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != checker->head)
		lst = lst->next;
	return (lst);
}

void
	ft_dlstadd_back(t_checker *checker, int num)
{
	t_dlist *new;
	t_dlist *ptr;

	new = malloc(sizeof(t_dlist));
	checker->tail->next = new;
	ptr = checker->head;
	ptr->prev = new;
	new->num = num;
	new->next = ptr;
	ptr = ft_dlstlast(checker, ptr);
	new->prev = checker->tail;
	checker->tail = new;
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

void
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
		ft_dlstadd_back(checker, num);
		i++;
	}
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
	pack_stack(&checker, av);
	display_stack(&checker);//for debug
	return (0);
}
