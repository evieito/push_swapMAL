#include "push_swap.h"
#include <limits.h>

int		choose_best_reinsert(t_node *a, t_node *b,
							int *best_idx_in_b, int *best_target_in_a)
{
	int n_b;
	int n_a;
	t_node *cur;
	int i;
	int best_cost;

	if (!b)
		return (0);
	n_b = stack_size(b);
	n_a = stack_size(a);
	cur = b;
	i = 0;
	best_cost = INT_MAX;
	while (cur)
	{
		int pos_b;
		int pos_a;
		int rb_cost;
		int ra_cost;
		int cand;

		pos_b = i;
		pos_a = find_pos_in_a(a, cur->index);
		if (pos_b <= n_b / 2)
			rb_cost = pos_b;
		else
			rb_cost = n_b - pos_b;
		if (pos_a <= n_a / 2)
			ra_cost = pos_a;
		else
			ra_cost = n_a - pos_a;
		cand = rb_cost + ra_cost;
		if (cand < best_cost)
		{
			best_cost = cand;
			*best_idx_in_b = pos_b;
			*best_target_in_a = pos_a;
		}
		cur = cur->next;
		i++;
	}
	if (best_cost == INT_MAX)
		return (0);
	return (1);
}

void	execute_reinsert(t_node **a, t_node **b, int best_idx_in_b, int best_target_in_a)
{
	int n_b;
	int n_a;
	int pb_up;
	int pa_up;

	n_b = stack_size(*b);
	n_a = stack_size(*a);
	pb_up = (best_idx_in_b <= n_b / 2);
	pa_up = (best_target_in_a <= n_a / 2);
	if (pb_up && pa_up)
	{
		while (best_idx_in_b > 0 && best_target_in_a > 0)
		{
			rr(a, b);
			best_idx_in_b--;
			best_target_in_a--;
		}
		while (best_idx_in_b--)
			rb(b);
		while (best_target_in_a--)
			ra(a);
	}
	else if (!pb_up && !pa_up)
	{
		int rb_down;
		int ra_down;

		rb_down = n_b - best_idx_in_b;
		ra_down = n_a - best_target_in_a;
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
		while (best_idx_in_b--)
			rb(b);
		int ra_down;

		ra_down = n_a - best_target_in_a;
		while (ra_down--)
			rra(a);
	}
	else
	{
		int rb_down;

		rb_down = n_b - best_idx_in_b;
		while (rb_down--)
			rrb(b);
		while (best_target_in_a--)
			ra(a);
	}
	pa(a, b);
}

void	final_rotate_a(t_node **a)
{
	int n;
	int min;
	t_node *t;
	int i;
	int pos_min;

	if (!a || !*a)
		return ;
	n = stack_size(*a);
	min = (*a)->index;
	t = *a;
	i = 0;
	pos_min = 0;
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
		int down;

		down = n - pos_min;
		while (down--)
			rra(a);
	}
}
