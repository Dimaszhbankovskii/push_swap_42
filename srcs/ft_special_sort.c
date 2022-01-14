#include "../includes/push_swap.h"

// static void	ft_special_sort_2(t_stack **stack, t_command **result)
// {
// 	t_stack	*tmp;

// 	tmp = *stack;
// 	if (tmp->order > tmp->next->order)
// 		do_command(&tmp, NULL, result, "sa");
// 	*stack = tmp;
// }

void	ft_special_sort(t_main *inf)
{
	int		unsort;

	unsort = ft_count_unsort_big(&(inf->stack_a));
	if (unsort == 1)
		do_command(inf, "ra");
	else if (unsort == 2)
	{
		if (inf->stack_a->order > inf->stack_a->next->order)
			do_command(inf, "sa");
		do_command(inf, "ra");
		do_command(inf, "ra");
	}
}
