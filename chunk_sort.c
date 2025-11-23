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

/* removed unused function: find_pos_of_index */

static int	size_to_chunks(int size)
{
	if (size <= 50)
		return 3;
	if (size <= 150)
		return 6;
	if (size <= 500)
		return 11;
	return 20;
}

/* rotate_a_to_pos removed (unused) */

static int find_pos_in_a(t_node *a, int index)
{
	if (!a)
		return 0;
	int pos = 0;
	t_node *t = a;
	int min = a->index;
	t_node *tmp = a;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	if (index < min)
	{
		pos = 0;
		t = a;
		while (t && t->index != min)
		{
			pos++;
			t = t->next;
		}
		return pos;
	}
	int i = 0;
	t = a;
	while (t && t->next)
	{
		if (t->index < index && index < t->next->index)
			return i + 1;
		i++;
		t = t->next;
	}
	return 0;
}

static int find_pos_in_b(t_node *b, int index)
{
	if (!b)
		return 0;
	int max = b->index;
	int min = b->index;
	t_node *t = b;
	int pos_max = 0;
	int i = 0;
	while (t)
	{
		if (t->index > max)
		{
			max = t->index;
			pos_max = i;
		}
		if (t->index < min)
			min = t->index;
		t = t->next;
		i++;
	}
	if (index > max)
		return pos_max;
	if (index < min)
	{
		/* position after min */
		t = b;
		i = 0;
		while (t && t->index != min)
		{
			i++;
			t = t->next;
		}
		return (i + 1) % (stack_size(b));
	}
	t = b;
	i = 0;
	while (t && t->next)
	{
		if (t->index > index && index > t->next->index)
			return i + 1;
		i++;
		t = t->next;
	}
	return 0;
}

/* rotate_b_up/down removed (not used) */




/* moves chunk elements from A to B (keeping B such that largest are on top) */
void	chunk_sort(t_node **a, t_node **b)
{
	int size = stack_size(*a);
	int chunks = size_to_chunks(size);
	int chunk_size = (size + chunks - 1) / chunks;
	int limit = chunk_size;
	assign_indices(*a);

	/* push everything except 3 to B, selecting best element in current chunk by combined cost */
	while (stack_size(*a) > 3)
	{
		int n_a = stack_size(*a);
		int n_b = stack_size(*b);
		t_node *t = *a;
		int i = 0;
		int best_pos_in_a = -1;
		int best_target_in_b = 0;
		int best_cost = INT_MAX;
    
		while (t)
		{
			if (t->index <= limit)
			{
				int pos_a = i;
				int cost_a = (pos_a <= n_a/2) ? pos_a : (n_a - pos_a);
				int target_b_pos = find_pos_in_b(*b, t->index);
				int cost_b = (n_b == 0) ? 0 : ((target_b_pos <= n_b/2) ? target_b_pos : (n_b - target_b_pos));
				int cand = cost_a + cost_b;
				if (cand < best_cost)
				{
					best_cost = cand;
					best_pos_in_a = pos_a;
					best_target_in_b = target_b_pos;
				}
			}
			i++;
			t = t->next;
		}

		if (best_pos_in_a == -1)
		{
			/* advance window */
			ra(a);
			if (stack_size(*b) >= limit && limit < size)
				limit += chunk_size;
			continue;
		}

		/* rotate A and B to best positions using combined rotations where possible, then push */
		int pos_a = best_pos_in_a;
		int pos_b = best_target_in_b;
		n_a = stack_size(*a);
		n_b = stack_size(*b);
		if (best_pos_in_a >= 0)
		{
			int a_up = (pos_a <= n_a/2);
			int b_up = (pos_b <= n_b/2);
			/* both up -> rr */
			if (n_b > 0 && a_up && b_up)
			{
				while (pos_a > 0 && pos_b > 0)
				{
					rr(a, b);
					pos_a--;
					pos_b--;
				}
				while (pos_a--)
					ra(a);
				while (pos_b--)
					rb(b);
			}
			/* both down -> rrr */
			else if (n_b > 0 && !a_up && !b_up)
			{
				int a_down = n_a - pos_a;
				int b_down = n_b - pos_b;
				while (a_down > 0 && b_down > 0)
				{
					rrr(a, b);
					a_down--;
					b_down--;
				}
				while (a_down--)
					rra(a);
				while (b_down--)
					rrb(b);
			}
			/* mixed directions */
			else
			{
				if (a_up)
					while (pos_a--)
						ra(a);
				else
				{
					int a_down = n_a - pos_a;
					while (a_down--)
						rra(a);
				}
				if (n_b > 0)
				{
					if (b_up)
						while (pos_b--)
							rb(b);
					else
					{
						int b_down = n_b - pos_b;
						while (b_down--)
							rrb(b);
					}
				}
			}
			pb(a, b);
			/* small heuristic: rotate b if the pushed index is in lower half of chunk to keep smaller near bottom */
			if (*b && (*b)->next && (*b)->index < (limit - chunk_size / 2))
				rb(b);
		}

		if (stack_size(*a) <= 3 && limit < size)
			limit = size;
		if (stack_size(*b) >= limit && limit < size)
			limit += chunk_size;
	}

	/* sort remaining 3 in A */
	/* call small_sort to order the small stack A before reinsertion */
	if (!is_sorted(*a))
		small_sort(a, b);

	/* reinsertion: choose best element in B to push (min total moves) */
	while (*b)
	{
		int n_b = stack_size(*b);
		int n_a = stack_size(*a);
		t_node *cur = *b;
		int best_idx_in_b = 0;
		int best_target_in_a = 0;
		int best_cost = INT_MAX;

		int i = 0;
		while (cur)
		{
			int pos_b = i;
			int pos_a = find_pos_in_a(*a, cur->index);

			int rb_cost = (pos_b <= n_b/2) ? pos_b : (n_b - pos_b);
			int ra_cost = (pos_a <= n_a/2) ? pos_a : (n_a - pos_a);

			int cost_both_up = (pos_b <= n_b/2 && pos_a <= n_a/2) ? ((pos_b > pos_a) ? pos_b : pos_a) : INT_MAX;
			int cost_both_down = (pos_b > n_b/2 && pos_a > n_a/2) ? (((n_b - pos_b) > (n_a - pos_a)) ? (n_b - pos_b) : (n_a - pos_a)) : INT_MAX;
			int cost_b_up_a_down = (pos_b <= n_b/2 && pos_a > n_a/2) ? (pos_b + (n_a - pos_a)) : INT_MAX;
			int cost_b_down_a_up = (pos_b > n_b/2 && pos_a <= n_a/2) ? ((n_b - pos_b) + pos_a) : INT_MAX;

			int cand = rb_cost + ra_cost;
			if (cost_both_up < cand) cand = cost_both_up;
			if (cost_both_down < cand) cand = cost_both_down;
			if (cost_b_up_a_down < cand) cand = cost_b_up_a_down;
			if (cost_b_down_a_up < cand) cand = cost_b_down_a_up;

			if (cand < best_cost)
			{
				best_cost = cand;
				best_idx_in_b = pos_b;
				best_target_in_a = pos_a;
			}

			cur = cur->next;
			i++;
		}

		/* perform rotations according to best positions */
		int pb_pos = best_idx_in_b;
		int pa_pos = best_target_in_a;
		n_b = stack_size(*b);
		n_a = stack_size(*a);

		int pb_up = (pb_pos <= n_b/2);
		int pa_up = (pa_pos <= n_a/2);

		if (pb_up && pa_up)
		{
			while (pb_pos > 0 && pa_pos > 0)
			{
				rr(a, b);
				pb_pos--;
				pa_pos--;
			}
			while (pb_pos--)
				rb(b);
			while (pa_pos--)
				ra(a);
		}
		else if (!pb_up && !pa_up)
		{
			int rb_down = n_b - pb_pos;
			int ra_down = n_a - pa_pos;
			while (rb_down > 0 && ra_down > 0)
			{
				rrr(a, b);
				rb_down--;
				ra_down--;
			}
			while (rb_down--)
				rrb(b);
			while (ra_down--)
				rra(a);
		}
		else if (pb_up && !pa_up)
		{
			while (pb_pos--)
				rb(b);
			int ra_down = n_a - pa_pos;
			while (ra_down--)
				rra(a);
		}
		else
		{
			int rb_down = n_b - pb_pos;
			while (rb_down--)
				rrb(b);
			while (pa_pos--)
				ra(a);
		}

		pa(a, b);
	}

	/* final rotate A so smallest element is at top */
	if (*a)
	{
		int n = stack_size(*a);
		int min = (*a)->index;
		t_node *t = *a;
		int i = 0;
		int pos_min = 0;
		while (t)
		{
			if (t->index < min)
			{
				min = t->index;
				pos_min = i;
			}
			i++;
			t = t->next;
		}
		if (pos_min <= n / 2)
			while (pos_min--)
				ra(a);
		else
		{
			int down = n - pos_min;
			while (down--)
				rra(a);
		}
	}
}
