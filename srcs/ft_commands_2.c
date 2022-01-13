#include "../includes/push_swap.h"

int	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	i = ft_sa_sb(stack_a);
	i = ft_sa_sb(stack_b);
	return (i);
}

int	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	i = ft_ra_rb(stack_a);
	i = ft_ra_rb(stack_b);
	return (i);
}

int	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	i = ft_rra_rrb(stack_a);
	i = ft_rra_rrb(stack_b);
	return (i);
}
