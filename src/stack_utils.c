#include "../inc/main.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*min_ptr;

	if (!stack)
		return (NULL);
	min = 2147483647;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_ptr = stack;
		}
		stack = stack->next;
	}
	return (min_ptr);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*max_ptr;

	if (!stack)
		return (NULL);
	max = -2147483647 - 1;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_ptr = stack;
		}
		stack = stack->next;
	}
	return (max_ptr);
}
