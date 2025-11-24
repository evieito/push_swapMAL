#include "push_swap.h"

static void	do_both_up(t_node **a, t_node **b, int pos_a, int pos_b)
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

static void	do_both_down(t_node **a, t_node **b, int pos_a, int pos_b)
{
	int a_down;
	int b_down;

	a_down = stack_size(*a) - pos_a;
	b_down = stack_size(*b) - pos_b;
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

static void	do_mixed(t_node **a, t_node **b, int pos_a, int pos_b)
{
	int n_a;
	int n_b;
	int a_up;
	int b_up;

	n_a = stack_size(*a);
	n_b = stack_size(*b);
	a_up = (pos_a <= n_a / 2);
	b_up = (pos_b <= n_b / 2);
	if (a_up)
		while (pos_a--)
			ra(a);
	else
	{
		int a_down;

		a_down = n_a - pos_a;
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
			int b_down;

			b_down = n_b - pos_b;
			while (b_down--)
				rrb(b);
		}
	}
}

void	perform_rotations_and_push(t_node **a, t_node **b, int pos_a, int pos_b)
{
	int n_b;
	int a_up;
	int b_up;

	n_b = stack_size(*b);
	a_up = (pos_a <= stack_size(*a) / 2);
	b_up = (pos_b <= n_b / 2);
	if (n_b > 0 && a_up && b_up)
		do_both_up(a, b, pos_a, pos_b);
	else if (n_b > 0 && !a_up && !b_up)
		do_both_down(a, b, pos_a, pos_b);
	else
		do_mixed(a, b, pos_a, pos_b);
	pb(a, b);
}
