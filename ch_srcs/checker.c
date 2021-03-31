#include "../includes/checker.h"

int
	ft_dlstadd_back(t_stacks *st, int num)
{
	t_dlist *new;

	if (!(new = malloc(sizeof(t_dlist))))
		return (FALSE);
	st->a.tail->next = new;
	st->a.head->prev = new;
	new->num = num;
	new->next = st->a.head;
	new->prev = st->a.tail;
	st->a.tail = new;
	return (TRUE);
}

void
	ft_dlstnew(t_stacks *st, int num)
{
	t_dlist *lst;

	lst = malloc(sizeof(t_dlist));
	lst->num = num;
	lst->next = lst;
	lst->prev = lst;
	st->a.head = lst;
	st->a.tail = lst;
}

int
	pack_stack(t_stacks *st, char **av)
{
	int	num;
	int	i;

	num = ft_atoi(av[1]);
	ft_dlstnew(st, num);
	i = 2;
	while (i < st->len)
	{
		num = ft_atoi(av[i]);
		if (ft_dlstadd_back(st, num) == FALSE)
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
	display_stack(t_stacks *st)
{
	t_dlist	*lst;
	int		i;

	printf("________________Stack_Circumstance____________________\n");
	printf("\n*****************\n>>>>>Stack_A<<<<<\n*****************\n");
	i = 1;
	lst = st->a.head;
	printf("%3d->%3d | addr->%p | prev->%p | next->%p\n", i, lst->num, lst, lst->prev, lst->next);
	i++;
	lst = lst->next;
	while (lst->next != st->a.head)
	{
		printf("%3d->%3d | addr->%p | prev->%p | next->%p\n", i, lst->num, lst, lst->prev, lst->next);
		i++;
		lst = lst->next;
	}
	printf("%3d->%3d | addr->%p | prev->%p | next->%p\n", i, lst->num, lst, lst->prev, lst->next);
}

int
	main(int ac, char **av)
{
	t_stacks	st;

	if ((st.len = ac) <= 1 || check_av(ac, av) == FALSE)
		return (FALSE);
	if (pack_stack(&st, av) == FALSE)
		return (FALSE);
	display_stack(&st);//for debug
	return (0);
}
