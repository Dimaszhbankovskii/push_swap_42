#include "../includes/push_swap.h"

void	ft_div_a(t_stack **a, t_stack **b, t_data *data, t_command **res)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		flag;

	tmp_a = *a;
	tmp_b = *b;
	flag = tmp_a->flag;
	while (tmp_a->flag == flag)
	{
		if (tmp_a->order == data->next)
		{
			do_command(&tmp_a, &tmp_b, res, "ra");
			data->next++;
		}
		else
			do_command(&tmp_a, &tmp_b, res, "pb");
	}
	*a = tmp_a;
	*b = tmp_b;
}

static void	ft_div_b_1(t_stack **a, t_stack **b, t_data *data, t_command **res)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	if (tmp_b->order == data->next)
	{
		tmp_b->flag = data->flag;
		do_command(&tmp_a, &tmp_b, res, "pa");
		do_command(&tmp_a, &tmp_b, res, "ra");
		data->next++;
	}
	if (tmp_b && tmp_b->order >= data->mid)
	{
		tmp_b->flag = data->flag;
		do_command(&tmp_a, &tmp_b, res, "pa");
	}
	else
		do_command(&tmp_a, &tmp_b, res, "rb");
	*a = tmp_a;
	*b = tmp_b;
}

static void	ft_div_b_2(t_stack **a, t_stack **b, t_data *data, t_command **res)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	ft_spec_sort_b(&tmp_a, &tmp_b, res);
	while (len_stack(&tmp_b))
	{
		tmp_b->flag = data->flag;
		do_command(&tmp_a, &tmp_b, res, "pa");
	}
	*a = tmp_a;
	*b = tmp_b;
}

int	ft_check_div_b_1(t_stack **stack, t_data *data)
{
	t_stack	*tmp;
	int		flag;

	tmp = *stack;
	flag = 1;
	while (tmp)
	{
		if (tmp->order >= data->mid)
			flag = 0;
		tmp = tmp->next;
	}
	return (flag);
}

void	ft_div_b(t_stack **a, t_stack **b, t_data *data, t_command **res)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_b && len_stack(&tmp_b) > 3)
	{
		update_data(data, &tmp_b);
		while (tmp_b && !ft_check_div_b_1(&tmp_b, data))
			ft_div_b_1(&tmp_a, &tmp_b, data, res);
	}
	if (tmp_b && len_stack(&tmp_b) <= 3)
		ft_div_b_2(&tmp_a, &tmp_b, data, res);
	*a = tmp_a;
	*b = tmp_b;
}

void	ft_block_1(t_stack **a, t_stack **b, t_data *data, t_command **res)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	ft_div_b(&tmp_a, &tmp_b, data, res);
	while (tmp_a->flag)
	{
		ft_div_a(&tmp_a, &tmp_b, data, res);
		ft_div_b(&tmp_a, &tmp_b, data, res);
	}
	*a = tmp_a;
	*b = tmp_b;
}
