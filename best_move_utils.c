#include "push_swap.h"
#include <stdlib.h>

void	assign_indices_local(t_node *a)
{
	t_node *i;
	t_node *j;
	int	count;

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

int	find_insert_pos_b(t_node *b, int idx)
{
	int pos;

	pos = 0;
	while (b)
	{
		if (b->index < idx)
			return (pos);
		pos++;
		b = b->next;
	}
	return (pos);
}

int	get_pos_of_node(t_node *s, t_node *target)
{
	int pos;

	pos = 0;
	while (s)
	{
		if (s == target)
			return (pos);
		pos++;
		s = s->next;
	}
	return (-1);
}

int	compute_cost(int a_pos, int a_size, int b_pos, int b_size)
{
	int a_rot;
	int b_rot;

	if (a_pos <= a_size / 2)
		a_rot = a_pos;
	else
		a_rot = a_pos - a_size;
	if (b_pos <= b_size / 2)
		b_rot = b_pos;
	else
		b_rot = b_pos - b_size;
	if ((a_rot >= 0 && b_rot >= 0) || (a_rot <= 0 && b_rot <= 0))
	{
		if (a_rot < 0)
		{
			if (-a_rot > -b_rot)
				return (-a_rot);
			return (-b_rot);
		}
		if (a_rot > b_rot)
			return (a_rot);
		return (b_rot);
	}
	if (a_rot < 0)
		a_rot = -a_rot;
	if (b_rot < 0)
		b_rot = -b_rot;
	return (a_rot + b_rot);
}

int	find_and_handle_best_node(t_node **a, t_node **b,
	int min_idx, int max_idx)
{
	t_node *best;

	best = pick_best_node(*a, *b, min_idx, max_idx);
	if (!best)
		return (0);
	perform_moves_for_node(a, b, best);
	return (1);
}
