#include "../includes/push_swap.h"

void	ft_special_sort(t_main *inf)
{
	int		unsort;

	unsort = count_unsort_stack_a(&(inf->stack_a));
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
