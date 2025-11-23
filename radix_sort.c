#include "push_swap.h"

static void	assign_indices(t_node *a)
{
	t_node	*i;
	t_node	*j;
	int		count;

	i = a;
	while (i)
	{
		count = 0;
		j = a;
		while (j)
		{
			if (j->value < i->value)
				count++;
			j = j->next;
		}
		i->index = count;
		i = i->next;
	}
}

void	radix_sort(t_node **a, t_node **b)
{
	int	size = stack_size(*a);
	int	max = 0;
	int	max_bits = 0;

	assign_indices(*a);

	for (t_node *tmp = *a; tmp; tmp = tmp->next)
		if (tmp->index > max)
			max = tmp->index;

	while ((max >> max_bits) != 0)
		max_bits++;

	for (int bit = 0; bit < max_bits; bit++)
	{
		for (int i = 0; i < size; i++)
		{
			if (((*a)->index >> bit) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
	}
}
