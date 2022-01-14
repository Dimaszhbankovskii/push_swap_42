#include "../includes/push_swap.h"

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	return (sa_sb(stack_a) || sa_sb(stack_b));
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	return (ra_rb(stack_a) && ra_rb(stack_b));
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	return (rra_rrb(stack_a) && rra_rrb(stack_b));
}
