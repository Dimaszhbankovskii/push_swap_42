#include "../includes/push_swap.h"

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	return (sa_sb(stack_a) || sa_sb(stack_b));
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	return (ra_rb(stack_a) || ra_rb(stack_b));
}

int	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	i = ft_rra_rrb(stack_a);
	i = ft_rra_rrb(stack_b);
	return (i);
}
