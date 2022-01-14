#include "../includes/push_swap.h"

static void	ft_rotate(t_main *inf)
{
	t_stack	*end_a;

	end_a = end_stack(&(inf->stack_a));
	while (end_a->flag == 0)
	{
		if (inf->stack_b->order == inf->data->next)
			do_command(inf, "rra");
		else
			do_command(inf, "rrr");
		end_a = end_stack(&(inf->stack_a));
	}
}

void	ft_block_2(t_main *inf)
{
	update_data(inf->data, &(inf->stack_a));
	while (!(inf->stack_a->flag))
	{
		if (inf->stack_a->order == inf->data->next)
		{
			if (inf->stack_a->order - end_stack(&(inf->stack_a))->order == 1)
			{
				inf->stack_a->flag++;
				do_command(inf, "ra");
				inf->data->next++;
			}
		}
		if (inf->stack_a->order <= inf->data->mid)
			do_command(inf, "pb");
		else
			do_command(inf, "ra");
	}
	ft_rotate(inf);
}
