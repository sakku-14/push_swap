#include <stdio.h>
#include <unistd.h>
#include "../includes/push_swap.h"

void
	pack_num(char **av, t_stack *stack_a)
{
	int		index;

	index = 0;
	stack_a->str_num = ft_split(av[1], ' ');
}

int
	main(int ac, char **av)
{
	t_stack	stack_a;

	if (ac < 2 || ac > 2)
		return (ERROR);
	ft_bzero(&stack_a, sizeof(t_stack));
	pack_num(av, &stack_a);
	int i;
	i = 0;
	while (stack_a.str_num[i])
		printf("%s\n", stack_a.str_num[i++]);
}
