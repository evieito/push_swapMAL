/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evieito- <evieito-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:00:00 by autopatch         #+#    #+#             */
/*   Updated: 2025/11/23 18:53:36 by evieito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/* helpers moved to chunk_utils*.c */




/* moves chunk elements from A to B (keeping B such that largest are on top) */
void	chunk_sort(t_node **a, t_node **b)
{
	int size;
	int chunks;
	int chunk_size;
	int limit;

	size = stack_size(*a);
	chunks = size_to_chunks(size);
	chunk_size = (size + chunks - 1) / chunks;
	limit = chunk_size;
	assign_indices(*a);
	while (stack_size(*a) > 3)
	{
		int best_a;
		int best_b;

		best_a = -1;
		if (!compute_best_in_chunk(*a, *b, limit, &best_a, &best_b))
		{
			if (limit < size)
				limit += chunk_size;
			continue;
		}
		perform_rotations_and_push(a, b, best_a, best_b);
		if (*b && (*b)->next && (*b)->index < (limit - chunk_size / 4))
			rb(b);
		if (stack_size(*a) <= 3 && limit < size)
			limit = size;
		if (stack_size(*b) >= limit && limit < size)
			limit += chunk_size;
	}
	if (!is_sorted(*a))
		small_sort(a, b);
	while (*b)
	{
		int best_idx;
		int best_target;

		if (!choose_best_reinsert(*a, *b, &best_idx, &best_target))
			break;
		execute_reinsert(a, b, best_idx, best_target);
	}
	final_rotate_a(a);
}
