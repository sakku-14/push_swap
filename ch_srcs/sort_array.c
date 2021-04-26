#include "../includes/checker.h"

void
	swap_num(int *nums, int l, int r)
{
	int tmp;

	tmp = nums[l];
	nums[l] = nums[r];
	nums[r] = tmp;
}

int
	swap_array(int *nums, int pivot, int *l, int *r)
{
	while (nums[*l] < pivot)
		(*l)++;
	while (nums[*r] > pivot)
		(*r)--;
	if (*l >= *r)
		return (FALSE);
	swap_num(nums, *l, *r);
	return (TRUE);
}

void
	q_sort_array(int *nums, int left, int right)
{
	int pivot;
	int l;
	int r;

	l = left;
	r = right;
	pivot = nums[l];
	while (1)
	{
		if (swap_array(nums, pivot, &l, &r) == FALSE)
			break ;
		l++;
		r--;
	}
	if (left < l - 1)
		q_sort_array(nums, left, l - 1);
	if (right > r + 1)
		q_sort_array(nums, r + 1, right);
}

void
	sort_array(int *nums, int len)
{
	q_sort_array(nums, 0, len - 1);
}