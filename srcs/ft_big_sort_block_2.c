#include "../includes/push_swap.h"

static void	ft_rotate(t_stack **a, t_stack **b, t_data *data, t_command **res)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*end_a;

	tmp_a = *a;
	tmp_b = *b;
	end_a = end_stack(&tmp_a);
	while (end_a->flag == 0)
	{
		if (tmp_b->order == data->next)
			do_command(&tmp_a, &tmp_b, res, "rra");
		else
			do_command(&tmp_a, &tmp_b, res, "rrr");
		end_a = end_stack(&tmp_a);
	}
	*a = tmp_a;
	*b = tmp_b;
}

void	ft_block_2(t_stack **a, t_stack **b, t_data *data, t_command **res)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	update_data(data, &tmp_a);
	while (!tmp_a->flag)
	{
		if (tmp_a->order == data->next)
		{
			if (tmp_a->order - end_stack(&tmp_a)->order == 1)
			{
				tmp_a->flag++;
				do_command(&tmp_a, &tmp_b, res, "ra");
				data->next++;
			}
		}
		if (tmp_a->order <= data->mid)
			do_command(&tmp_a, &tmp_b, res, "pb");
		else
			do_command(&tmp_a, &tmp_b, res, "ra");
	}
	ft_rotate(&tmp_a, &tmp_b, data, res);
	*a = tmp_a;
	*b = tmp_b;
}
