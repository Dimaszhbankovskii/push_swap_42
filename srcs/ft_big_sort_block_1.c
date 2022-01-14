#include "../includes/push_swap.h"

void	partition_a(t_main *inf)
{
	int		flag;

	flag = inf->stack_a->flag;
	while (inf->stack_a->flag == flag)
	{
		if (inf->stack_a->order == inf->data->next)
		{
			do_command(inf, "ra");
			inf->data->next++;
		}
		else
			do_command(inf, "pb");
	}
}

static void	move_b(t_main *inf)
{
	if (inf->stack_b->order == inf->data->next)
	{
		inf->stack_b->flag = inf->data->flag;
		do_command(inf, "pa");
		do_command(inf, "ra");
		inf->data->next++;
	}
	if (inf->stack_b && inf->stack_b->order >= inf->data->mid)
	{
		inf->stack_b->flag = inf->data->flag;
		do_command(inf, "pa");
	}
	else
		do_command(inf, "rb");
}

static void	ft_div_b_2(t_main *inf)
{
	ft_spec_sort_b(inf);
	while (len_stack(&(inf->stack_b)))
	{
		inf->stack_b->flag = inf->data->flag;
		do_command(inf, "pa");
	}
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

void	partition_b(t_main *inf)
{
	while (inf->stack_b && len_stack(&(inf->stack_b)) > 3)
	{
		update_data(inf->data, &(inf->stack_b));
		while (inf->stack_b && !ft_check_div_b_1(&(inf->stack_b), inf->data))
			move_b(inf);
	}
	if (inf->stack_b && len_stack(&(inf->stack_b)) <= 3)
		ft_div_b_2(inf); // -----
}

void	ft_block_1(t_main *inf)
{
	partition_b(inf);
	while (inf->stack_a->flag)
	{
		partition_a(inf);
		partition_b(inf);
	}
}
