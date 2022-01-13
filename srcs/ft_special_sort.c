#include "../includes/push_swap.h"

static void	ft_special_sort_2(t_stack **stack, t_command **result)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->order > tmp->next->order)
		do_command(&tmp, NULL, result, "sa");
	*stack = tmp;
}

void	ft_special_sort(t_stack **stack_a, t_stack **stack_b, t_command **result)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		unsort;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	unsort = ft_count_unsort_big(&tmp_a);
	if (unsort == 1)
		do_command(&tmp_a, NULL, result, "ra");
	else if (unsort == 2)
	{
		ft_special_sort_2(&tmp_a, result);
		do_command(&tmp_a, NULL, result, "ra");
		do_command(&tmp_a, NULL, result, "ra");
	}
	*stack_a = tmp_a;
	*stack_b = tmp_b;
}
