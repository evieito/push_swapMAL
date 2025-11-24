#include "push_swap.h"

int	find_pos_in_range(t_node *a, int min, int max)
{
    int pos;
    int first;
    int last;

    pos = 0;
    first = -1;
    last = -1;
    while (a)
    {
        if (a->index >= min && a->index <= max)
        {
            if (first == -1)
                first = pos;
            last = pos;
        }
        pos++;
        a = a->next;
    }
    if (first == -1)
        return (-1);
    if (first <= pos - last)
        return (first);
    return (last);
}

int	find_pos_max(t_node *b)
{
    int pos;
    int max;
    t_node *tmp;

    pos = 0;
    max = -1;
    tmp = b;
    while (tmp)
    {
        if (tmp->index > max)
            max = tmp->index;
        tmp = tmp->next;
    }
    tmp = b;
    pos = 0;
    while (tmp)
    {
        if (tmp->index == max)
            return (pos);
        pos++;
        tmp = tmp->next;
    }
    return (0);
}
