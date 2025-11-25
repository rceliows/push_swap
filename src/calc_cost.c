#include "../inc/main.h"

static int	get_rotation_cost(t_stack_node *node, int stack_len)
{
	if (node->above_median)
		return (node->index);
	else
		return (stack_len - node->index);
}

static int	calc_same_direction_cost(int cost_a, int cost_b)
{
	if (cost_a > cost_b)
		return (cost_a);
	else
		return (cost_b);
}

int	calc_optimal_cost(t_stack_node *a, t_stack_node *target,
		int len_a, int len_b)
{
	int	cost_a;
	int	cost_b;
	int	separate_cost;
	int	same_dir_cost;

	cost_a = get_rotation_cost(a, len_a);
	cost_b = get_rotation_cost(target, len_b);
	separate_cost = cost_a + cost_b;
	if (a->above_median == target->above_median)
	{
		same_dir_cost = calc_same_direction_cost(cost_a, cost_b);
		if (same_dir_cost < separate_cost)
			return (same_dir_cost);
	}
	return (separate_cost);
}
