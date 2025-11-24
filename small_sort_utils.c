#include "push_swap.h"

void	push_min_to_b(t_node **a, t_node **b)
{
	int pos;
	int n;

	pos = find_min_pos(*a);
	n = stack_size(*a);
	if (pos == 0)
		pb(a, b);
	else if (pos <= n / 2)
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		pos = n - pos;
		while (pos > 0)
		{
			rra(a);
			pos--;
		}
	}
	if (stack_size(*a) > 3)
		pb(a, b);
}
