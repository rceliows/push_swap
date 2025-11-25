#include "inc/push_swap.h"

static int	validate_args(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (validate_args(argc, argv))
		return (1);
	if (argc == 2)
		argv = split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
