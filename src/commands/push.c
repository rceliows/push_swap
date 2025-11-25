#include "../../inc/main.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*temp_node;

	if (!*src)
		return ;
	temp_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp_node->prev = NULL;
	if (!*dst)
	{
		*dst = temp_node;
		temp_node->next = NULL;
	}
	else
	{
		temp_node->next = *dst;
		temp_node->next->prev = temp_node;
		*dst = temp_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, int print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, int print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
