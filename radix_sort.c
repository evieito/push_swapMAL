#include "push_swap.h"

#include <stdlib.h>

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

/* moved helpers to radix_utils.c */

void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	chunk_count;
	int	chunk_size;
    

	size = stack_size(*a);
	assign_indices(*a);
	if (size > 100)
	{
		best_move_sort(a, b);
		return ;
	}
	{
		int	target;

		if (size <= 100)
			target = 20;
		else if (size <= 500)
			target = 20;
		else
			target = 40;
		chunk_count = size / target;
		if (chunk_count == 0)
			chunk_count = 1;
	}
	chunk_size = size / chunk_count;
	if (chunk_size == 0)
		chunk_size = 1;
	push_chunks_to_b(a, b, chunk_size, size);
	rebuild_a_from_b(a, b);
}
