#include "../includes/checker.h"

int
	ft_dlstadd_back(t_stack *stack, int num, int exist)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (new == NULL)
		return (FALSE);
	stack->tail->next = new;
	stack->head->prev = new;
	new->num = num;
	new->exist = exist;
	new->next = stack->head;
	new->prev = stack->tail;
	stack->tail = new;
	return (TRUE);
}

int
	ft_dlstnew(t_stack *stack, int num, int exist)
{
	t_dlist	*lst;

	lst = malloc(sizeof(t_dlist));
	if (lst == NULL)
		return (FALSE);
	lst->num = num;
	lst->exist = exist;
	lst->next = lst;
	lst->prev = lst;
	stack->head = lst;
	stack->tail = lst;
	return (TRUE);
}
