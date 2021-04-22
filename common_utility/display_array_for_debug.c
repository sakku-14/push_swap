#include "../includes/common_utility.h"

//FOR debug
void
	display_array(int *x, int len)
{
	int i = 0;
	while (i < len)
		printf("%d-", x[i++]);
	printf("\n");
}
