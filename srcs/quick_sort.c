#include "../includes/push_swap.h"

static void	rotate_a_b(t_main *inf)
{
	t_stack	*end_a;

	end_a = end_stack(&(inf->a));
	while (end_a->flag == 0)
	{
		if (inf->b->order == inf->data->next)
			do_command(inf, "rra");
		else
			do_command(inf, "rrr");
		end_a = end_stack(&(inf->a));
	}
}

static void	next_partition_a(t_main *inf)
{
	update_data(inf->data, &(inf->a));
	while (!(inf->a->flag))
	{
		if (inf->a->order == inf->data->next)
		{
			if (inf->a->order - end_stack(&(inf->a))->order == 1)
			{
				inf->a->flag++;
				do_command(inf, "ra");
				inf->data->next++;
			}
		}
		if (inf->a->order <= inf->data->mid)
			do_command(inf, "pb");
		else
			do_command(inf, "ra");
	}
	rotate_a_b(inf);
}

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
	inf->data->max = find_max_value_order(&(inf->a));
	inf->data->mid = inf->data->max / 2 + inf->data->next;
	while (!check_first_partition_a(&(inf->a), inf->data))
	{
		if (inf->a->order <= inf->data->mid)
			do_command(inf, "pb");
		else
			do_command(inf, "ra");
	}
}

void	quick_sort(t_main *inf)
{
	first_partition_a(inf);
	while (!check_sort_stack(&(inf->a)) || inf->b)
	{
		sort_half_stack_a(inf);
		if (count_unsort_stack_a(&(inf->a)) >= 3)
			next_partition_a(inf);
		else
		{
			if (count_unsort_stack_a(&(inf->a)) == 1)
				do_command(inf, "ra");
			else if (count_unsort_stack_a(&(inf->a)) == 2)
			{
				if (inf->a->order > inf->a->next->order)
					do_command(inf, "sa");
				do_command(inf, "ra");
				do_command(inf, "ra");
			}
		}
	}
}
