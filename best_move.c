#include "push_swap.h"
#include <stdlib.h>

void	best_move_sort(t_node **a, t_node **b)
{
	int size;
	int chunk_size;
	int min_idx;
	int max_idx;
	int target;

	size = stack_size(*a);
	assign_indices_local(*a);
	target = get_chunk_target(size);
	if (target <= 0)
		target = 1;
	chunk_size = target;
	if (chunk_size > size)
		chunk_size = size;
	min_idx = 0;
	max_idx = chunk_size - 1;
	while (*a)
	{
		if (!find_and_handle_best_node(a, b, min_idx, max_idx))
		{
			min_idx += chunk_size;
			max_idx += chunk_size;
			if (max_idx > size - 1)
				max_idx = size - 1;
		}
	}
	while (*b)
		pa(a, b);
}

