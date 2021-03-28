#include "../includes/checker.h"

t_stack
	*lstnew(int num)
{
	t_stack *ret;

	ret = NULL;
	ret->num = num;
	ret->prev = ret;
	ret->next = ret;
	return (ret);
}

void
	pack_stack(t_checker *checker, char **av)
{
	//TODO: pack av to stack
	int	first_num;

	first_num = ft_atoi(av[1]);
	checker->top = lstnew(first_num);
}

int
	main(int ac, char **av)
{
	t_checker	checker;

	pack_stack(&checker, av);
	printf("ac:%d,num:%d\n", ac, checker.top->num);
	return (0);
}
