#include "push_swap.h"

static int	find_min_pos(t_node *a)
{
	int		min;
	int		pos;
	int		i;

	min = a->value;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			pos = i;
		}
		i++;
		a = a->next;
	}
	return (pos);
}

static void	sort_three(t_node **a)
{
	int	x = (*a)->value;
	int	y = (*a)->next->value;
	int	z = (*a)->next->next->value;

	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	small_sort(t_node **a, t_node **b)
{
	int	 size = stack_size(*a);

	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	if (size == 3)
		return (sort_three(a));

	/* small sort for 4 or 5 */
	while (stack_size(*a) > 3)
	{
		int pos = find_min_pos(*a);
		int n = stack_size(*a);
		if (pos == 0)
			pb(a, b);
		else if (pos <= n / 2)
			while (pos--)
				ra(a);
		else
		{
			pos = n - pos;
			while (pos--)
				rra(a);
		}
		if (stack_size(*a) > 3)
			pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
