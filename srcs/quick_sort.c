#include "../includes/push_swap.h"

static int	check_first_partition_a(t_stack **stack, t_data *data)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->order <= data->mid)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	first_partition_a(t_main *inf)
{
	inf->data->max = find_max_value_order(&(inf->stack_a));
	inf->data->mid = inf->data->max / 2 + inf->data->next;
	while (!check_first_partition_a(&(inf->stack_a), inf->data))
	{
		if (inf->stack_a->order <= inf->data->mid)
			do_command(inf, "pb");
		else
			do_command(inf, "ra");
	}
}

void	quick_sort(t_main *inf)
{
	first_partition_a(inf);
	while (!check_sort_stack(&(inf->stack_a)) || inf->stack_b)
	{
		ft_block_1(inf);
		if (ft_count_unsort_big(&(inf->stack_a)) >= 3)
			ft_block_2(inf);
		else
			ft_special_sort(inf);
	}
}
