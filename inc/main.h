#ifndef MAIN_H
# define MAIN_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

// Handle errors
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);

// Stack initiation
void			init_stack_a(t_stack_node **a, char **argv);
char			**split(char *s, char c);

// Nodes initiation
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);

// Stack utils
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
int				stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void			min_on_top(t_stack_node **a);
int				calc_optimal_cost(t_stack_node *a, t_stack_node *target,
					int len_a, int len_b);

// Commands
void			sa(t_stack_node **a, int print);
void			sb(t_stack_node **b, int print);
void			ss(t_stack_node **a, t_stack_node **b, int print);
void			ra(t_stack_node **a, int print);
void			rb(t_stack_node **b, int print);
void			rr(t_stack_node **a, t_stack_node **b, int print);
void			rra(t_stack_node **a, int print);
void			rrb(t_stack_node **b, int print);
void			rrr(t_stack_node **a, t_stack_node **b, int print);
void			pa(t_stack_node **a, t_stack_node **b, int print);
void			pb(t_stack_node **b, t_stack_node **a, int print);

// Algorithm
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

#endif
