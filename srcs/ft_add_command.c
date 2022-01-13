#include "../includes/push_swap.h"

void	write_command(t_command **result, char const *str, int done)
{
	t_command	*tmp;

	tmp = *result;
	while (tmp->command)
		tmp = tmp->next;
	if (done == 1)
	{
		tmp->command = ft_strdup(str);
		tmp->next = create_new_result();
		tmp->next->prev = tmp;
	}
}

void	do_command(t_stack **stack_a, t_stack **stack_b, \
t_command **result, char const *str)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "sa") == 0)
		i = ft_sa_sb(stack_a);
	else if (ft_strcmp(str, "sb") == 0)
		i = ft_sa_sb(stack_b);
	else if (ft_strcmp(str, "ss") == 0)
		i = ft_ss(stack_a, stack_b);
	else if (ft_strcmp(str, "pa") == 0)
		i = ft_pa_pb(stack_b, stack_a);
	else if (ft_strcmp(str, "pb") == 0)
		i = ft_pa_pb(stack_a, stack_b);
	else if (ft_strcmp(str, "ra") == 0)
		i = ft_ra_rb(stack_a);
	else if (ft_strcmp(str, "rb") == 0)
		i = ft_ra_rb(stack_b);
	else if (ft_strcmp(str, "rr") == 0)
		i = ft_rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra") == 0)
		i = ft_rra_rrb(stack_a);
	else if (ft_strcmp(str, "rrb") == 0)
		i = ft_rra_rrb(stack_b);
	else if (ft_strcmp(str, "rrr") == 0)
		i = ft_rrr(stack_a, stack_b);
	write_command(result, str, i);
}
