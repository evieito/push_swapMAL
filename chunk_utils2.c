#include "push_swap.h"
#include <limits.h>

static int	calc_cost_a(int pos_a, int n_a)
{
    if (pos_a <= n_a / 2)
        return (pos_a);
    return (n_a - pos_a);
}

static int	calc_cost_b(int pos_b, int n_b)
{
    if (n_b == 0)
        return (0);
    if (pos_b <= n_b / 2)
        return (pos_b);
    return (n_b - pos_b);
}

int		compute_best_in_chunk(t_node *a, t_node *b, int limit,
							int *best_pos_in_a, int *best_target_in_b)
{
    t_node *t;
    int i;
    int n_a;
    int n_b;
    int best_cost;

    if (!a)
        return (0);
    t = a;
    i = 0;
    n_a = stack_size(a);
    n_b = stack_size(b);
    best_cost = INT_MAX;
    while (t)
    {
        if (t->index <= limit)
        {
            int pos_a;
            int cost_a;
            int target_b_pos;
            int cost_b;

            pos_a = i;
            cost_a = calc_cost_a(pos_a, n_a);
            target_b_pos = find_pos_in_b(b, t->index);
            cost_b = calc_cost_b(target_b_pos, n_b);
            {
                int cand;

                cand = cost_a + cost_b;
                if (cand < best_cost)
                {
                    best_cost = cand;
                    *best_pos_in_a = pos_a;
                    *best_target_in_b = target_b_pos;
                }
            }
        }
        i++;
        t = t->next;
    }
    if (best_cost == INT_MAX)
        return (0);
    return (1);
}
