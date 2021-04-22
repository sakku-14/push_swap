#include "../includes/common_utility.h"

int
	print_error(void)
{
	write(1, "Error\n", 6);
	return (FALSE);
}

int
	exit_error(void)
{
	write(1, "Error\n", 6);
	exit (-1);
}