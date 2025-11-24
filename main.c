#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;

	if (argc < 2)
		return (0);

	parse_args(&a, argc, argv);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);

	return (0);
}
