#include "../includes/push_swap.h"

static int	ft_check_first_div_a(t_stack **stack, t_data *data)
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

static void	ft_first_div_a(t_stack **a, t_stack **b, t_data *data, t_command **res)
{
	t_stack *tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	data->max = find_max_value_order(&tmp_a);
	data->mid = data->max / 2 + data->next;
	while (!ft_check_first_div_a(&tmp_a, data))
	{
		if (tmp_a->order <= data->mid)
			do_command(&tmp_a, &tmp_b, res, "pb");
		else
			do_command(&tmp_a, &tmp_b, res, "ra");
	}
	*a = tmp_a;
	*b = tmp_b;
}

void	quick_sort(t_stack **a, t_stack **b, t_data *data, t_command **res)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;

	ft_first_div_a(&tmp_a, &tmp_b, data, res);
	while (!check_sort_stack(&tmp_a) || tmp_b)
	{
		ft_block_1(&tmp_a, &tmp_b, data, res);
		if (ft_count_unsort_big(&tmp_a) >= 3)
			ft_block_2(&tmp_a, &tmp_b, data, res);
		else
			ft_special_sort(&tmp_a, &tmp_b, res);
	}
	*a = tmp_a;
	*b = tmp_b;
}
