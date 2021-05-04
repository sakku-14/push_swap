#include "../includes/checker.h"

int
	exit_error(void)
{
	write(1, "Error\n", 6);
	exit (-1);
}
