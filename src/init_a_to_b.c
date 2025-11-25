#include "../inc/main.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			closest_small_num;

	while (a)
	{
		closest_small_num = -2147483647 - 1;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > closest_small_num)
			{
				closest_small_num = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_small_num == -2147483647 - 1)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = 2147483647;
	while (stack)
	{
		stack->cheapest = 0;
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = calc_optimal_cost(a, a->target_node, len_a, len_b);
		a = a->next;
	}
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
