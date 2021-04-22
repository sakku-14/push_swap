#include "../includes/common_utility.h"

void
	display_stack(t_stacks *st, char *str)
{
	t_dlist	*lst;
	int		i;
	char	flag;

	printf("\n________________Stack_Circumstance____________________\n");
	printf("----------%s----------\n", str);
	printf("*****************\n>>>>>Stack_A<<<<<\n*****************\n");
	i = 1;
	lst = st->a.head;
	if (lst == st->a.head && lst == st->a.tail)
		printf("h&t--->");
	else if (lst == st->a.head)
		printf("head-->");
	else
		printf("       ");
	if (lst->exist == 1)
		flag = 'o';
	else
		flag = 'x';
	printf("%3d->%3d(%d) | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, lst->group, flag, lst, lst->prev, lst->next);
	i++;
	lst = lst->next;
	while (lst != st->a.head)
	{
		if (lst == st->a.head && lst == st->a.tail)
			printf("h&t--->");
		else if (lst == st->a.tail)
			printf("tail-->");
		else
			printf("       ");
		if (lst->exist == 1)
			flag = 'o';
		else
			flag = 'x';
		printf("%3d->%3d(%d) | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, lst->group, flag, lst, lst->prev, lst->next);
		i++;
		lst = lst->next;
	}

	printf("*****************\n>>>>>Stack_B<<<<<\n*****************\n");
	i = 1;
	lst = st->b.head;
	if (lst == st->b.head && lst == st->b.tail)
		printf("h&t--->");
	else if (lst == st->b.head)
		printf("head-->");
	else
		printf("       ");
	if (lst->exist == 1)
		flag = 'o';
	else
		flag = 'x';
	printf("%3d->%3d(%d) | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, lst->group, flag, lst, lst->prev, lst->next);
	i++;
	lst = lst->next;
	while (lst != st->b.head)
	{
		if (lst == st->b.head && lst == st->b.tail)
			printf("h&t--->");
		else if (lst == st->b.tail)
			printf("tail-->");
		else
			printf("       ");
		if (lst->exist == 1)
			flag = 'o';
		else
			flag = 'x';
		printf("%3d->%3d(%d) | %c | addr->%p | prev->%p | next->%p\n", i, lst->num, lst->group, flag, lst, lst->prev, lst->next);
		i++;
		lst = lst->next;
	}
}
