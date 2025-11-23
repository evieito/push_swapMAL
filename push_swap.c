#include "push_swap.h"

void	push_swap(t_node **a, t_node **b)
{
	int	size;

	if (is_sorted(*a))
		return ;

	size = stack_size(*a);

	if (size <= 5)
		small_sort(a, b);
	else
		radix_sort(a, b);
}
