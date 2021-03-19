#include <unistd.h>
#include <stdio.h>
#include "../includes/checker.h"

int
	main(int ac, char **av)
{
	char *line;

	printf("%d\n%s\n", ac, av[1]);
	get_next_line(0, &line);

	return (0);
}
