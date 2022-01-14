#include "../includes/push_swap.h"

int	check_sort_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->order > tmp->next->order)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	count_unsort_stack_a(t_stack **stack)
{
	t_stack	*tmp;
	int		count;

	tmp = *stack;
	count = 0;
	while (tmp->flag == 0)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
